#!/bin/bash

pwd

g++ -fexceptions -std=c++11 -g -I../../../src clamper_test.cpp             -o clamper_test
g++ -fexceptions -std=c++11 -g -I../../../src peano_test.cpp               -o peano_test
g++ -fexceptions -std=c++11 -g -I../../../src distribution.cpp             -o distribution
g++ -fexceptions -std=c++11 -g -I../../../src vap.cpp                      -o vap
g++ -fexceptions -std=c++11 -g -I../../../src gabor.cpp                    -o gabor
g++ -fexceptions -std=c++11 -g -I../../../src bais.cpp                     -o bais
g++ -fexceptions -std=c++11 -g -I../../../src gain.cpp                     -o gain
g++ -fexceptions -std=c++11 -g -I../../../src val.cpp                      -o val
g++ -fexceptions -std=c++11 -g -I../../../src power.cpp                    -o power
g++ -fexceptions -std=c++11 -g -I../../../src factorial.cpp                -o factorial

