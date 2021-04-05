#!/bin/bash

pwd

g++ -fexceptions -std=c++11 -g -I../../../../../src check.cpp               -o  check
g++ -fexceptions -std=c++11 -g -I../../../../../src frustum.cpp             -o  frustum
