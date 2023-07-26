#!/bin/sh
# Script to create a file at given directory and writes a given value.
# Author: Atanas Mihaylov

writefile="$1"
writestr="$2"

if [ $# -lt 2 ]
then
	echo "Wrong number of arguments!"
	exit 1
fi

dirname=${writefile%/*}

if [ -d $dirname ]
then
	echo $writestr > $writefile
else
	mkdir -p $dirname
	echo $writestr > $writefile
fi
