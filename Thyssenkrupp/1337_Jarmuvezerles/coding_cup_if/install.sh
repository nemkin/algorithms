#!/bin/bash

mkdir bin
sudo apt install libopencv-dev
cd src/player
mkdir bin
cd bin
cmake ..
make

