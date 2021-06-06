#!/bin/bash

export BENCHMARK_NAME=mkdir-5.2.1
export BIN_NAME=mkdir-5.2.1-m-rwx
export BENCHMARK_DIR=$CHISEL_BENCHMARK_HOME/benchmark/$BIN_NAME/merged
export SRC=$BENCHMARK_DIR/$BENCHMARK_NAME.c
export ORIGIN_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.origin
export REDUCED_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.reduced
export TIMEOUT="-k 0.1 0.1"
export LOG=$BENCHMARK_DIR/log.txt
export LOG2=$BENCHMARK_DIR/log2.txt

source $CHISEL_BENCHMARK_HOME/benchmark/test-base.sh

function clean() {
  rm -rf d1 temp1 temp2 $LOG $LOG2 $REDUCED_BIN
  GLOBIGNORE=*.c:*.reduced:*.origin:*.mk:*.sh
  rm -rf ./'-m' ./'-v' ./'--help' ./'-p'
  rm -rf *
  unset GLOBIGNORE
  return 0;
}

function run() {
  rm -rf $2
  touch temp1
  { timeout $TIMEOUT $REDUCED_BIN $1 $2; } >&$LOG || exit 1
  (ls -ald $2 2>/dev/null | cut -d ' ' -f 1,2,3,4) > temp1
  rm -rf $2 >&/dev/null
  { $ORIGIN_BIN $1 $2; } >&$LOG2 || exit 1
  (ls -ald $2 2>/dev/null | cut -d ' ' -f 1,2,3,4) > temp2
  rm -rf $2 >&/dev/null
  diff -q temp1 temp2 || exit 1
  return 0;
}

function run_error() {
  rm -rf d1 >&/dev/null
  { timeout $TIMEOUT $REDUCED_BIN $1 $2; } >&temp1 && exit 1
  rm -rf d1 >&/dev/null
  { $ORIGIN_BIN $1 $2; } >&temp2
  (head -n 1 temp1 | cut -d ' ' -f 2,3) > temp1
  (head -n 1 temp2 | cut -d ' ' -f 2,3) > temp2
  rm -rf $2 123124
  diff -q temp1 temp2 || exit 1
  return 0;
}

function run2() {
  rm -rf $2 $3 >&/dev/null
  { timeout $TIMEOUT $REDUCED_BIN $1 $2 $3; } >&$LOG || exit 1
  (ls -ald $2 2>/dev/null | cut -d ' ' -f 1,2,3,4) > temp11
  (ls -ald $3 2>/dev/null | cut -d ' ' -f 1,2,3,4) > temp12
  rm -rf $2 $3 >&/dev/null
  { $ORIGIN_BIN $1 $2 $3; } >&$LOG2 || exit 1
  (ls -ald $2 2>/dev/null | cut -d ' ' -f 1,2,3,4) > temp21
  (ls -ald $3 2>/dev/null | cut -d ' ' -f 1,2,3,4) > temp22
  rm -rf $2 $3 >&/dev/null
  diff -q temp11 temp21 || exit 1
  diff -q temp12 temp22 || exit 1
  return 0;
}

# tests
function desired() {
  run "" d1 || exit 1
  run_error "" d1/d2 || exit 1
  run_error "-m 123124" d1/d2 || exit 1
  run_error "-m" d1/d2 || exit 1
  run "-m a=rwx" d1 || exit 1
  run2 "-m a=rwx" d1 d2 || exit 1

  GLOBIGNORE=*.c:*.reduced:*.origin:*.mk:*.sh
  rm -rf ./'-m' ./'-v' ./'--help' ./'-p'
  rm -rf *
  unset GLOBIGNORE
  return 0
}

OPT=("-m" "-p" "-v" "--help")
function undesired() {
  export srcdir=$(pwd)/../
  export PATH="$(pwd):$PATH"
  { timeout $TIMEOUT $REDUCED_BIN; } >&/dev/null
  crash $? && exit 1
  touch file
  for opt in ${OPT[@]}; do
    { timeout $TIMEOUT $REDUCED_BIN $opt file; } >&/dev/null
    crash $? && exit 1
  done
  return 0
}

function run_disaster() {
  rm -rf d1
  { timeout $TIMEOUT $REDUCED_BIN $1 $2; } >&$LOG
  grep -q -E "$3" $LOG
  if [[ $? -gt 0 ]]; then
    exit 1
  fi
  return 0
}

function desired_disaster() {
  case $1 in
  memory)
    MESSAGE="memory exhausted"
    ;;
  file) # mkdir does not cause this error
    return 0
    ;;
  *)
    return 1
    ;;
  esac
  run_disaster "-m a=rwx" d1 "$MESSAGE" || exit 1
  rm -rf d1 ./'a=rwx'
  return 0
}

main
