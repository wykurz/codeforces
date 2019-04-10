#!/usr/bin/env bash

function ns_time {
    date +%s%N
}

function run_make {
    echo "|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
    echo "Make! "`date '+%X'`
    make contest
}

function waitfile {
    if python waitfile.py $1
    then
       return 0
    fi
    return 1
}

ts=$(ns_time)
run_make
while waitfile $ts; do
    ts=$(ns_time)
    run_make
done
