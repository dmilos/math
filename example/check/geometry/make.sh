#!/bin/bash

echo [$(date)]$(pwd)
 

g++ -fexceptions -std=c++11 -g -I../../../src coord.cpp               -o  coord

cd ./circle
./make.sh
cd ..

cd ./direction
./make.sh
cd ..

cd ./ellipse
./make.sh
cd ..

cd ./interval
./make.sh
cd ..

cd ./plane
./make.sh
cd ..

cd ./projective
./make.sh
cd ..

cd ./quadric
./make.sh
cd ..

cd ./tetrahedron
./make.sh
cd ..

cd ./triangle
./make.sh
cd ..

