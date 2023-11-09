# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(ModelTest_003)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Set output diretory to ./build
set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)

# Add main.cpp as an executable target
add_executable(${PROJECT_NAME} main.cpp)

# Include headers from 3D_Objects & Geometry /headers directories
# (TODO)
include_directories(headers/3D_Objects)
include_directories(headers/Geometry)
include_directories(headers/Operations)

# Add source files from 3D_Objects & Geometry /src directories
# (TODO)
file(GLOB SOURCES src/3D_Objects/*.cpp)
file(GLOB SOURCES src/Geometry/*.cpp)
file(GLOB SOURCES src/Operations/*.cpp)

# Add source files to the executable target
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
