#!/bin/bash

mkdir bin;
g++ src/*.cpp -o bin/dirTree;
if [ $? -eq 0 ]; then
	command bin/dirTree "${@}";
fi;

exit 0;