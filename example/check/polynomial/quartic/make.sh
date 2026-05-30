#!/bin/bash

echo [$(date)]$(pwd)

g++ -fexceptions -std=c++11 -g -I../../../../src evaluate.cpp       -o  evaluate
g++ -fexceptions -std=c++11 -g -I../../../../src interpolate.cpp    -o  interpolate
g++ -fexceptions -std=c++11 -g -I../../../../src solve.cpp          -o  solve