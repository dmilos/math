#!/bin/bash

echo [$(date)]$(pwd)
 

g++ -fexceptions -std=c++11 -g -I../../../src variation_test.cpp               -o  variation_test
g++ -fexceptions -std=c++11 -g -I../../../src combination_test.cpp             -o  combination_test

