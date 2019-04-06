#!/usr/bin/env bash

function run_make
{
    echo "|+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
    echo "Make! "`date '+%X'`
    make contest
}

function continue
{
    if python waitfile.py
    then
       return 0
    fi
    return 1
}

run_make
while continue; do
    run_make
done
