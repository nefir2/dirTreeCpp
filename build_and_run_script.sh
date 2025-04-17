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

g++ -std=c++17 "${srcdir}/*${srcfilesext}" -o "${bindir}/${projfilename}";

if [ $? -eq 0 ]; then
	echo -e "\nbuild completed.\nrunning the program . . . \n-------------------------------------";
	command "${bindir}/${projfilename}" "${@}";
else
	echo "build is not completed.";
fi;

exit $?;