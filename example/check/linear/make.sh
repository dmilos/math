#!/bin/bash

echo [$(date)]$(pwd)
 

cd ./affine
./make.sh
cd .. 

cd ./homography
./make.sh
cd ..  

cd ./matrix
./make.sh
cd ..  

cd ./vector
./make.sh
cd ..   