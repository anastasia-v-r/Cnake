<div align="center">
    <img src="ghAssets/cpp_logo.png" alt="Cpp" height="60" align="bottom" />
    <font size="15">nake</font> <br>
    <font size="6">A snake Clone using SFML</font>
    <hr />
</div>
<br>

[![Build Status](https://img.shields.io/travis/Faunsce/Cnake.svg?label=Build)](https://travis-ci.org/Faunsce/Cnake)
[![GitHub pre-release](https://img.shields.io/github/release-pre/Faunsce/Cnake.svg?label=Pre-Release)](https://github.com/Faunsce/Cnake/releases/latest)
[![License](https://img.shields.io/github/license/faunsce/Cnake.svg?label=License)](https://choosealicense.com/licenses/mit/)
[![my server](https://discordapp.com/api/guilds/487130552613339137/widget.png?)](https://discord.gg/bxb5fbV)
## What is this?
This is a clone of the famous "Snake" game coded in [C++](http://cplusplus.com) with the aid of [SFML](http://sfml-dev.org) and other libraries.  

## Table of contents
[Game Showcase](#game-showcase)
  * [Intro](#-intro-screen)
  * [Menu](#-menu-screen)
  * [Settings](#-settings-screen)
  * [Game](#-gameplay-screen)
  * [Pause](#-pause-screen)
  * [Game Over](#-game-over-screen)

[Self Build Instructions](#how-to-build-yourself)
  * [Windows](#Windows-(In-Progress-))
  * [Linux](#Linux-(In-Progress-))
  * [OSX](#OSX-(In-Progress-))  

[Dependencies](#dependencies)  
[Contributing](#contributions)  
[License](#license)  
[Credits](#credits)

## Game Showcase
  * ### Intro Screen
  ![](https://i.imgur.com/ltp5awi.png)
  * ### Menu Screen
  ![](https://i.imgur.com/okBqpmP.png)
  * ### Settings Screen
  ![](https://i.imgur.com/3d24weM.png)
  * ### Gameplay Screen
  ![](https://i.imgur.com/ARgy7qC.png)
  * ### Pause Screen
  ![](https://i.imgur.com/3mBBr6k.png)
  * ### Game Over Screen
  ![](https://i.imgur.com/IvkvkuG.png)  

## How to build yourself
  ### Windows (In Progress)
  1. Install python
      - Install [Python](https://pypi.org/project/pip/)
      - export PATH="/c/Python37:/c/Python37/Scripts:$PATH"
      - python -m pip install --upgrade pip
  2. Install Cmake and conan
      - Run `pip install conan`
      - Run `pip install cmake`
      - export PATH=$PATH:/c/Program\ Files/Conan/conan
      - conan user
      - conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
  3. In the project root, make a conan folder and build conan inside
      - Run `makedir conan && cd conan`
      - Run `conan install .. -s build_type=Release -b missing` *you can change Release to Debug*
      - Run `cd ..`
  4. In the project root, make a build folder and build cmake inside
      - Run `makedir build && cd build`
      - Run `cmake ..`
      - Run `cmake --build .`
  ### Linux (In Progress)
  1. Install Cmake and conan
      - Install [Python](https://pypi.org/project/pip/)
      - pip install --user --upgrade pip
      - pip install --user conan --upgrade
      - export PATH=$PATH:/Users/travis/Library/Python/2.7/bin
  2. In the project root, make a conan folder and build conan inside
      - Run `makedir conan && cd conan`
      - Run `conan install .. -s build_type=Release -b missing` *you can change Release to Debug*
      - Run `cd ..`
      - conan user
      - conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
  3. In the project root, make a build folder and build cmake inside
      - Run `makedir build && cd build`
      - Run `cmake ..`
      - Run `cmake --build .`
  ### OSX (In Progress)
  1. Install Cmake and conan
      - Install [Python](https://pypi.org/project/pip/)
      - pip install --user --upgrade pip
      - pip install --user conan --upgrade
  1. In the project root, make a conan folder and build conan inside
      - Run `makedir conan && cd conan`
      - Run `conan install .. -s build_type=Release -b missing` *you can change Release to Debug*
      - Run `cd ..`
      - conan user
      - conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
  2. In the project root, make a build folder and build cmake inside
      - Run `makedir build && cd build`
      - Run `cmake ..`
      - Run `cmake --build .`
     

## Dependencies
- [SFML v2.5.1](https://www.sfml-dev.org/)
  - Statically Linked
  - Window, Graphics, and Audio modules
- [Json for modern c++ v3.7.0](https://github.com/nlohmann/json)


## Contributions
If you wish to contribute to my little project here for some odd reason,  
you are welcome to do so but just follow a few things. 

  1. Format your code like mine. If my code is against standard, let me know and I'll change it. 
  2. No additional dependencies.
  3. Any and all contributions meeting those standards are appreciated and will be looked at.

## License
This project is under the [MIT License](https://choosealicense.com/licenses/mit/)

## Credits
[Pickup_03](https://freesound.org/people/LittleRobotSoundFactory/sounds/270342/)"eat.wav" by [Little Robot Sound Factory](https://freesound.org/people/LittleRobotSoundFactory/) under the [Attribution 3.0 Unported License](https://creativecommons.org/licenses/by/3.0/legalcode)
[Hit_03](https://freesound.org/people/LittleRobotSoundFactory/sounds/270332/)"die.wav" by [Little Robot Sound Factory](https://freesound.org/people/LittleRobotSoundFactory/) under the [Attribution 3.0 Unported License](https://creativecommons.org/licenses/by/3.0/legalcode)
