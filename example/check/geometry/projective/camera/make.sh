#!/bin/bash

echo [$(date)]$(pwd)
 

g++ -fexceptions -std=c++11 -g -I../../../../../src rectify.cpp             -o  rectify
g++ -fexceptions -std=c++11 -g -I../../../../../src check.cpp               -o  check
g++ -fexceptions -std=c++11 -g -I../../../../../src frustum.cpp             -o  frustum
g++ -fexceptions -std=c++11 -g -I../../../../../src focus.cpp               -o  focus
