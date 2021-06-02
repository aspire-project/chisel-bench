#!/bin/bash
UTIL="uniq-8.16"
FLAGS="-cd"
ARGS=""

function compute_outputs(){
    dir=$1
    outputfolder=$dir/outputs
    obin=$dir/$UTIL.origin
    rbin=$dir/$UTIL$FLAGS.chisel

    mkdir -p $outputfolder

    for file in $(ls $dir/test/*); do
        # echo $rbin $flags $file
        routfile=$outputfolder/$(basename $file).out.reduced
        ooutfile=$outputfolder/$(basename $file).out.origin
        $rbin $FLAGS $file >& $routfile
        $obin $FLAGS $file >& $ooutfile
        diff -q $routfile $ooutfile >& /dev/null || exit 1
    done
    return 0
}

function compare_outputs(){
    return 0
}

function test_one(){
    dir=$1
    compute_outputs "$dir"
    compare_outputs 
}

test_one $(pwd)
