#!/bin/bash
export BENCHMARK_NAME=wc
export BENCHMARK_DIR=$CHISEL_BENCHMARK_HOME/benchmark/pdb_$BENCHMARK_NAME
export SRC=$BENCHMARK_DIR/$BENCHMARK_NAME.c
export ORIGIN_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.origin
export REDUCED_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.reduced
export TIMEOUT="-k 1 1"
export LOG=$BENCHMARK_DIR/log.txt
export TESTENV=$BENCHMARK_DIR/testenv

source $CHISEL_BENCHMARK_HOME/benchmark/test-base.sh

function clean() {
  # TODO
  return 0
}

function test(){
  FILE=$1
  FLAGS=$2
  diff -q \
    <(cat $FILE | $ORIGIN_BIN $FLAGS) \
    <(cat $FILE | $REDUCED_BIN $FLAGS) \
    >& /dev/null || return 1
  return 0
}

function desired() {
  DEFUALT_TEST_FILE="testfile"
  test "$DEFUALT_TEST_FILE" ""    || return 1
  test "$DEFUALT_TEST_FILE" "-c"  || return 1
  test "$DEFUALT_TEST_FILE" "-l"  || return 1
  test "$DEFUALT_TEST_FILE" "-w"  || return 1
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