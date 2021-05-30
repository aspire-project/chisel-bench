#!/bin/bash
export BENCHMARK_NAME=ls
export BENCHMARK_DIR=$CHISEL_BENCHMARK_HOME/benchmark/bsysi_$BENCHMARK_NAME
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
  FILE=$1
  ARGS=$2
  diff -q \
    <(timeout $TIMEOUT $ORIGIN_BIN $ARGS "$FILE") \
    <(timeout $TIMEOUT $REDUCED_BIN $ARGS "$FILE") \
    >&/dev/null || return 1
  return 0
}

# -l	Long listing format
# -S	Sort by size
# -R	List subdirectories recursively
# -h	with -l and -s, print sizes like 1K 234M 2G etc.
# -a	list hidden files as well 

function create_test_env(){
  mkdir -p $TESTENV/{1..4}/{1..4}
  touch $TESTENV/{1,2}/{a,b} $TESTENV/{3,4}/{3,4}/{c,d}
  echo "dummytext dummytext dummytext dummytext dummytext" >> $TESTENV/4/4/d
}

function desired() {
  create_test_env
  test "."    || return 1
  test "$TESTENV" "-l"  || return 1
  test "$TESTENV" "-S"  || return 1
  test "$TESTENV" "-R"  || return 1
  test "$TESTENV" "-h"  || return 1
  test "$TESTENV" "-a"  || return 1
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