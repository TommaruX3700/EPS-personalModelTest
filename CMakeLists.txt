cmake_minimum_required(VERSION 3.10)

# Set the project name
project(EPS_MODEL)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directory to ./build
set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)

# Add all .cpp files in the directory to the executable
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*/*/*.cpp)

# Add main.cpp as an executable target
add_executable(${PROJECT_NAME} main.cpp)

# Include headers
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/headers  
    ${PROJECT_SOURCE_DIR}/headers/entities/geometry
    ${PROJECT_SOURCE_DIR}/headers/entities/physical
    ${PROJECT_SOURCE_DIR}/headers/logic
    ${PROJECT_SOURCE_DIR}/extLibs/nlohmannJSON
)

# Add source files to the executable target
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
