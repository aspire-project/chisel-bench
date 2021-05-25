#!/bin/bash
export BENCHMARK_NAME=dd
export BENCHMARK_DIR=$CHISEL_BENCHMARK_HOME/benchmark/bsysi_$BENCHMARK_NAME
export SRC=$BENCHMARK_DIR/$BENCHMARK_NAME.c
export ORIGIN_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.origin
export REDUCED_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.reduced
export TIMEOUT="-k 1 1"
export LOG=$BENCHMARK_DIR/log.txt
export TESTENV=$BENCHMARK_DIR/testenv
export COREUTILS_DIR=$BENCHMARK_DIR

source $CHISEL_BENCHMARK_HOME/benchmark/test-base-make.sh

function clean() {
  # TODO
  return 0
}

function test(){
  FILE=$1
  ARG_VALS=$2
  for n in $ARG_VALS; do
    diff -q \
    <(cat $FILE | $ORIGIN_BIN -$n) \
    <(cat $FILE | $REDUCED_BIN -$n) \
    >&/dev/null || exit 1
  done
}

function desired() {
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