# Version Setup
cmake_minimum_required(VERSION 3.1...3.14.3)

if (${CMAKE_VERSION} VERSION_LESS 3.14)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
    cmake_policy(VERSION 3.14)
endif()

# Project Creation
project (Cnake)
set (CMAKE_CXX_STANDARD 17)
option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)

# Conan
if(EXISTS ${CMAKE_SOURCE_DIR}/conan/conanbuildinfo.cmake)
    include(${CMAKE_SOURCE_DIR}/conan/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    if(EXISTS ${CMAKE_SOURCE_DIR}/conanfile.txt)
        message( FATAL_ERROR
" A conanfile.txt file exists in the source directory\n"
" indicating conan is used for dependences but a conanbuildinfo.cmake\n"
" file does not exist. Make sure to execute:\n\n"
" conan install ${CMAKE_SOURCE_DIR} --build=missing -if ${CMAKE_BINARY_DIR}" )
    endif()
endif()

# .exe
add_executable(Cnake src/main.cpp src/player.h src/fs.hpp src/player.cpp)
set_target_properties(Cnake PROPERTIES
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
	CXX_STANDARD 17
	)
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  target_link_libraries(Cnake stdc++fs)
endif()
target_link_libraries(Cnake ${CONAN_LIBS})
