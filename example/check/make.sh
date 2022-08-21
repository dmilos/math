#!/bin/bash

echo [$(date)]$(pwd)
 

cd ./algorithm
./make.sh
cd ..

cd ./complex
./make.sh
cd ..

cd ./function
./make.sh
cd ..

cd ./geometry
./make.sh
cd ..

cd ./linear
./make.sh
cd ..

cd ./polynomial
./make.sh
cd ..

cd ./random
./make.sh
cd ..

cd ./statistic
./make.sh
cd ..

cd ./topology
./make.sh
cd ..

