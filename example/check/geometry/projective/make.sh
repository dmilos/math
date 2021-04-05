#!/bin/bash

pwd

g++ -fexceptions -std=c++11 -g -I../../../../src check.cpp               -o  check 


cd ./camera
./make.sh
cd .. 