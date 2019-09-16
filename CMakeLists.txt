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
set (WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin/assets)
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

find_package(nlohmann_json 3.2.0 REQUIRED)

# Program Asset Management
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/bin)

# Program Executable Creation
FILE(GLOB sources ${CMAKE_SOURCE_DIR}/src/* # Append all src files to an env. var.
	${CMAKE_SOURCE_DIR}/src/mode/*
) 
add_executable(Cnake ${sources}) # Create executable
set_target_properties(Cnake PROPERTIES 
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS OFF
	CXX_STANDARD 17 # Force c++17 standard
)

# Include Directories
target_include_directories(Cnake PUBLIC ${CMAKE_SOURCE_DIR}/include)


# For Filthy MacOS
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU") 
  target_link_libraries(Cnake stdc++fs)
endif()

conan_target_link_libraries(Cnake)
target_link_libraries(Cnake nlohmann_json::nlohmann_json)