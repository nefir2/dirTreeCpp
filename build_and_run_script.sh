#!/bin/bash

mkdir bin;
g++ src/* -o bin/dirTree;
if [ $? -eq 0 ]; then
	command bin/dirTree;
fi;

exit 0;