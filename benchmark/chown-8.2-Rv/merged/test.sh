#!/bin/bash

export BENCHMARK_NAME=chown-8.2
export BIN_NAME=chown-8.2-Rv
export BENCHMARK_DIR=$CHISEL_BENCHMARK_HOME/benchmark/$BIN_NAME/merged
export SRC=$BENCHMARK_DIR/$BENCHMARK_NAME.c
export ORIGIN_BIN=$BENCHMARK_DIR/$BENCHMARK_NAME.origin
export REDUCED_BIN=$BENCHMARK_DIR/$BIN_NAME.reduced
export TIMEOUT="-k 0.1 0.1"
export LOG=$BENCHMARK_DIR/log.txt

source $CHISEL_BENCHMARK_HOME/benchmark/test-base.sh

function clean() {
  rm -rf $LOG $REDUCED_BIN d1 temp temp1 temp2 file log symfile1 symfile2
  rm -rf cu-*
  return 0
}

function printlog(){
  # cat $LOG
  # echo "-----"
  # cat log2
  # echo "====="
  return 0
}

# $1 : option, $2 : file for reduced, $3 : file for original
function run() {
  { timeout $TIMEOUT $REDUCED_BIN $1 $(whoami):sudo $2; }  2>&1 | cut -d" " -f1,6,8 >&$LOG || exit 1
  ls -al $2 | cut -d ' ' -f 4 >temp1
  $ORIGIN_BIN $1 $(whoami):sudo $3 2>&1 | cut -d" " -f1,6,8 >&log2
  ls -al $3 | cut -d ' ' -f 4 >temp2
  printlog
  diff -q temp1 temp2 >&/dev/null || exit 1
  diff -q $LOG log2 >&/dev/null || exit 1

  { timeout $TIMEOUT $REDUCED_BIN $1 $(whoami):$(whoami) $2; }  2>&1 | cut -d" " -f1,6,8 >&$LOG || exit 1
  ls -al $2 | cut -d ' ' -f 4 >temp1
  $ORIGIN_BIN $1 $(whoami):$(whoami) $3  2>&1 | cut -d" " -f1,6,8  >&log2
  ls -al $3 | cut -d ' ' -f 4 >temp2
  printlog
  diff -q temp1 temp2 >&/dev/null || exit 1
  diff -q $LOG log2 >&/dev/null || exit 1

  { timeout $TIMEOUT $REDUCED_BIN $1 $(whoami):$(whoami) $2; } 2>&1 | cut -d" " -f1,6,8 >&$LOG || exit 1
  ls -al $2 | cut -d ' ' -f 4 >temp1
  $ORIGIN_BIN $1 $(whoami):$(whoami) $3  2>&1 | cut -d" " -f1,6,8  >&log2
  ls -al $3 | cut -d ' ' -f 4 >temp2
  printlog
  diff -q $LOG log2 >&/dev/null || exit 1

  return 0
}

function desired() {
  mkdir -p d1/d1/d1
  touch d1/d1/d1/file
  mkdir -p d2/d2/d2
  touch d2/d2/d2/file
  run "-Rv" d1 d2 || exit 1
  ls -al d1/d1/d1/file | cut -d ' ' -f 4 >temp1
  ls -al d2/d2/d2/file | cut -d ' ' -f 4 >temp2
  diff -q temp1 temp2 >&/dev/null || exit 1
  rm -rf d1 d2

  return 0
}

function run_disaster() {
  { timeout $TIMEOUT $REDUCED_BIN $1 $(whoami):sudo $2; } >&$LOG
  cat $LOG | grep -E -q "$4" || exit 1
  { timeout $TIMEOUT $REDUCED_BIN $1 $(whoami):$(whoami) $2; } >&$LOG
  cat $LOG | grep -E -q "$4" || exit 1
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

  mkdir -p d1/d1/d1
  touch d1/d1/d1/file
  mkdir -p d2/d2/d2
  touch d2/d2/d2/file
  run_disaster "-Rv" d1 d2 "$MESSAGE" || exit 1
  ls -al d1/d1/d1/file | cut -d ' ' -f 4 >temp1
  ls -al d2/d2/d2/file | cut -d ' ' -f 4 >temp2
  diff -q temp1 temp2 >&/dev/null || exit 1
  rm -rf d1 d2

  return 0
}

function outputcheck() {
  r="$1"
  if grep -q -E "$r" $LOG; then
    return 1
  fi
  return 0
}

OPT=("" "-c" "-f" "-H" "-L" "-P")
function undesired() {
  { timeout 0.5 $REDUCED_BIN; } >&$LOG
  err=$?
  outputcheck "missing operand" && exit 1
  crash $err && exit 1
  { timeout 0.5 $REDUCED_BIN input1 input2 notexist; } >&$LOG
  err=$?
  outputcheck "invalid user" && exit 1
  crash $err && exit 1
  { timeout 0.5 $REDUCED_BIN notexist; } >&$LOG
  err=$?
  outputcheck "missing operand after \`notexist'" && exit 1
  crash $err && exit 1
  export srcdir=$BENCHMARK_HOME/../
  export PATH="$(pwd):$PATH"
  touch file
  for opt in ${OPT[@]}; do
    { timeout 0.5 $REDUCED_BIN $opt file; } >&$LOG
    err=$?
    outputcheck "missing operand after \`file'" && exit 1
    crash $err && exit 1
  done
  { timeout 0.5 $REDUCED_BIN --help; } >&$LOG
  crash $? && exit 1
  return 0
}

main
