ECHO Creating Conan Resources
mkdir conan && cd conan
conan install ..
cd ..
ECHO Creating Cmake Resources
mkdir cmake && cd cmake
cmake ..
cd ..
ECHO Setup Complete
