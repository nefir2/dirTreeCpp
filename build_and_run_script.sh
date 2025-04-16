#!/bin/bash

export bindir="bin";
export srcdir="src";
export srcfilesext=".cpp";
export projfilename="dirTree";

command -v g++;
if [ $? -ne 0 ]; then
	echo "g++ is not found.";
	exit $?;
fi;

if [ ! -d "$srcdir" ]; then
	echo "$srcdir is not found.";
	exit -1;
fi;

if [ ! -d "$bindir" ]; then
	mkdir "$bindir";
fi;

g++ "${srcdir}/*${srcfilesext}" -o "${bindir}/${projfilename}";

if [ $? -eq 0 ]; then
	command "${bindir}/${projfilename}" "${@}";
fi;

exit 0;