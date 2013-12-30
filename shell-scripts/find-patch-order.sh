#!/bin/bash

# source rpm path
SRPM=$1

# input file is the output generated by rpmbpuild -bp 2>&1
INPUTFILE=$2

if [ $# -ne 2 ]
then
    exit -1
fi

for p in `rpm -qp --nosignature --qf "[%{PATCH}\n]" "$SRPM"`
do
    # echo grep  -n "$p" $INPUTFILE
    echo "$p" `grep -n "$p" $INPUTFILE | cut -d: -f1 `
done
