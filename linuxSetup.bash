#!/bin/bash
echo Creating Conan Resources
mkdir conan && cd conan
conan install ..
cd ..
echo Creating Cmake Resources
mkdir cmake && cd cmake
cmake ..
cd ..
echo Setup Complete
