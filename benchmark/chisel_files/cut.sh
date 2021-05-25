#!/bin/bash
export BENCHMARK_NAME=cut
export BENCHMARK_DIR=$CHISEL_BENCHMARK_HOME/benchmark/pdb_$BENCHMARK_NAME
export SRC=$BENCHMARK_DIR/$BENCHMARK_NAME.c
export ORIGIN_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.origin
export REDUCED_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.reduced
export TIMEOUT="-k 1 1"
export LOG=$BENCHMARK_DIR/log.txt
export TESTENV=$BENCHMARK_DIR/testenv

source $CHISEL_BENCHMARK_HOME/benchmark/test-base-make.sh

function clean() {
  rm -rf $TESTENV
  return 0
}

function test(){
  ARGS=$1
  F=$2
  OUTPUT_ORIG=$({ timeout $TIMEOUT $ORIGIN_BIN $ARGS $F; } 2>&1 || exit 1)
  OUTPUT_REDU=$({ timeout $TIMEOUT $REDUCED_BIN $ARGS $F; } 2>&1 || exit 1)
  diff -q \
    <(echo $OUTPUT_ORIG) \
    <(echo $OUTPUT_REDU) \
    >&/dev/null
  
  return 0
}


function create_test_env(){
  mkdir -p $TESTENV
  echo -e "1\t2,a\n3\t4,b\n5\t6,c\n7\t8,d" > $TESTENV/test
  return 0
}

function desired() {
  FILE=`create_test_env`
  test '-f1'        "$TESTENV/$FILE" || return 1
  test '-f2'        "$TESTENV/$FILE" || return 1
  test '-d, -f1'    "$TESTENV/$FILE" || return 1
  test '-d, -f2'    "$TESTENV/$FILE" || return 1
  test '-c1,2,3'    "$TESTENV/$FILE" || return 1
  return 0
}

function undesired() {
  OPT=("-b" "-n" "-v" "-s" "-z" "--help")
  for opt in ${OPT[@]}; do
    { timeout $TIMEOUT $REDUCED_BIN $opt file; } >&/dev/null
    crash $? && return 1
  done
  return 0
}

function desired_disaster_run() {
  { timeout $TIMEOUT $REDUCED_BIN $1 data.txt; } >&$LOG
  grep -E -q "$2" $LOG || exit 1
  return 0
}

function desired_disaster() {
  case $1 in
  memory)
    MESSAGE="memory exhausted"
    ;;
  file)
    MESSAGE="write error"
    ;;
  *)
    return 1
    ;;
  esac

  FILE=`create_test_env`
  desired_disaster_run '-f1'        "$TESTENV/$FILE" "$MESSAGE" || return 1
  desired_disaster_run '-f2'        "$TESTENV/$FILE" "$MESSAGE" || return 1
  desired_disaster_run '-d, -f1'    "$TESTENV/$FILE" "$MESSAGE" || return 1
  desired_disaster_run '-d, -f2'    "$TESTENV/$FILE" "$MESSAGE" || return 1
  desired_disaster_run '-c1,2,3'    "$TESTENV/$FILE" "$MESSAGE" || return 1
  return 0
}

main
