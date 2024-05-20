#!/bin/bash

# Make all examples.
# No Scons, no CMake, no Make or any other make tool
# One line one example
# Designed for easy copy/paste

reset

echo [$(date)]$(pwd)
g++ --version


g++ -fexceptions -std=c++11 -g -I../src readme.cpp               -o  readme

cd ./check
./make.sh
cd ..


cd ./test
./make.sh
cd ..


echo "Done"

