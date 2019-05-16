# Version Setup
cmake_minimum_required(VERSION 3.1...3.14.3)

if (${CMAKE_VERSION} VERSION_LESS 3.14)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.14)
endif()

set (CXX_STANDARD_REQUIRED ON)
set (CXX_EXTENSIONS OFF)
set (CXX_STANDARD 17)

# Project Creation
project (Cnake)

# Conan
include(${CMAKE_SOURCE_DIR}/conan/conanbuildinfo.cmake)
conan_basic_setup()

# .exe
add_executable(Cnake src/main.cpp src/player.h src/player.cpp)
target_link_libraries(Cnake ${CONAN_LIBS})
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  target_link_libraries(Cnake stdc++fs)
endif()