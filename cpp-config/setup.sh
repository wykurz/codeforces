#!/usr/bin/env bash

set -xe

CPP_CONF=cpp-config
NAME=$1
PROBLEM_PATH=problemset/$NAME

function do_ln
{
    ln -s ../../$CPP_CONF/$1 $PROBLEM_PATH/$1
}

mkdir $PROBLEM_PATH
cp $CPP_CONF/template.cpp $PROBLEM_PATH/sol.cpp
touch $PROBLEM_PATH/input.txt
do_ln .clang_complete
do_ln Makefile
do_ln runmake.sh
do_ln waitfile.py
