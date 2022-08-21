#!/bin/bash

echo [$(date)]$(pwd)
 

g++ -fexceptions -std=c++11 -g -I../../../../src check.cpp               -o  check 
g++ -fexceptions -std=c++11 -g -I../../../../src test.cpp               -o  test 
