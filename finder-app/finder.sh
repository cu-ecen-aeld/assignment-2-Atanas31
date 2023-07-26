#!/bin/sh
# Script accepting two arguments - path & file name -  and searching if the file exist
# Author: Atanas Mihaylov

filesdir="$1"
searchstr="$2"

if [ $# -lt 2 ]
then
	echo "Wrong number of arguments"
	exit 1
fi

if [ -d $filesdir ]
then
	echo "The number of files are $(find $filesdir -type f | wc -l) and the number of matching lines are $(grep -Ro $searchstr $filesdir | wc -w)"
else
	echo "$1 is not a directory!"
fi
