#!/bin/bash

echo [$(date)]$(pwd)
 

cd ./solve
./make.sh
cd ..

cd ./interpolate
./make.sh
cd ..

g++ -fexceptions -std=c++11 -g -I../../../src evaluate.cpp               -o  evaluate
g++ -fexceptions -std=c++11 -g -I../../../src normalize.cpp               -o  normalize
g++ -fexceptions -std=c++11 -g -I../../../src optimize.cpp               -o  optimize
g++ -fexceptions -std=c++11 -g -I../../../src fit.cpp                    -o  fit
