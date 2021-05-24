#!/bin/bash
export BENCHMARK_NAME=head
export BENCHMARK_DIR=$CHISEL_BENCHMARK_HOME/benchmark/pdb_$BENCHMARK_NAME
export SRC=$BENCHMARK_DIR/$BENCHMARK_NAME.c
export ORIGIN_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.origin
export REDUCED_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.reduced
export TIMEOUT="-k 1 1"
export LOG=$BENCHMARK_DIR/log.txt
export TESTENV=$BENCHMARK_DIR/testenv

source $CHISEL_BENCHMARK_HOME/benchmark/test-base.sh

function clean() {
  rm testfile
  return 0
}

function test(){
  FILE=$1
  FLAGS=$2
  diff -q \
    <(cat $FILE | $ORIGIN_BIN $FLAGS) \
    <(cat $FILE | $REDUCED_BIN $FLAGS) \
    >&/dev/null || return 1
  
  return 0
}

function test_no_flag(){
  test "$FILE" "" || return 1
  return 0
}

function test_flag_n(){
  FILE=$1
  ARG_VALS=$2
  for n in $ARG_VALS; do
    test "$FILE" "-$n" || return 1
  done
  return 0
}

function desired() {
  echo -ne "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n" > testfile
  test_no_flag  "testfile"  ""      || return 1
  test_flag_n   "testfile"  "1 5"   || return 1
  return 0
}

function undesired() {
  # TODO
  return 0
}

function desired_disaster() {
  # TODO
  return 0
}

# main
desired