#!/bin/bash

echo [$(date)]$(pwd)
  

g++ -fexceptions -std=c++11 -g -I../../../src sobol_test.cpp               -o  sobol_test
