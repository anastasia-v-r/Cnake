<div align="center">
    <img src="ghAssets/cpp_logo.png" alt="Cpp" height="50" align="bottom" />
    <font size="7">nake</font> <br>
    <font size="4">A snake Clone using SFML</font>
    <hr />
</div>
<br>

[![Build Status](https://img.shields.io/travis/Faunsce/Cnake.svg?label=Build)](https://travis-ci.org/Faunsce/Cnake)
[![GitHub pre-release](https://img.shields.io/github/release-pre/Faunsce/Cnake.svg?label=Pre-Release)](https://github.com/Faunsce/Cnake/releases/latest)
[![License](https://img.shields.io/github/license/faunsce/Cnake.svg?label=License)](https://choosealicense.com/licenses/mit/)
[![my server](https://discordapp.com/api/guilds/487130552613339137/widget.png?)](https://discord.gg/bxb5fbV)
## What is this?
This is a clone of the famous "Snake" game coded in [C++](http://cplusplus.com) with the aid of [SFML](http://sfml-dev.org).  

## How to build yourself
  #### Windows (In Progress)
  1. Install Cmake and conan
      - Install [Chocolatey](https://chocolatey.org/)
      - Run `choco install conan`
      - Run `choco install cmake`
  2. In the project root, make a conan folder and build conan inside
      - Run `makedir conan && cd conan`
      - Run `conan install ..`
      - Run `cd ..`
  3. In the project root, make a build folder and build cmake inside
      - Run `makedir build && cd build`
      - Run `cmake ..`
      - Run `cmake --build .`
  #### Linux (In Progress)
  1. Install Cmake and conan
      - Install [Python](https://pypi.org/project/pip/)
      - Run `pip install conan`
      - Run `pip install cmake`
  2. In the project root, make a conan folder and build conan inside
      - Run `makedir conan && cd conan`
      - Run `conan install ..`
      - Run `cd ..`
  3. In the project root, make a build folder and build cmake inside
      - Run `makedir build && cd build`
      - Run `cmake ..`
      - Run `cmake --build .`
  #### OSX (In Progress)
  1. Install Cmake and conan
      - Install [Python](https://pypi.org/project/pip/)
      - Run `pip install update`
      - Run `pip install cmake`
  2. In the project root, make a conan folder and build conan inside
      - Run `makedir conan && cd conan`
      - Run `conan install ..`
      - Run `cd ..`
  3. In the project root, make a build folder and build cmake inside
      - Run `makedir build && cd build`
      - Run `cmake ..`
      - Run `cmake --build .`
     

## Dependencies && Resource
SFML v2.5.1
- All the static libraries
- All includes  

Conan v1.11.1  
Cmake v3.1+

## Contributions
If you wish to contribute to my little project here for some odd reason,  
you are welcome to do so but just follow a few things. 

  1. Format your code like mine. If my code is against standard, let me know and I'll change it. 
  2. Try not to add any additional dependencies to the project.
  3. Any and all contributions meeting those standards are appreciated and will be looked at.

## License
This project is under the [MIT License](https://choosealicense.com/licenses/mit/)
