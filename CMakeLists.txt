cmake_minimum_required(VERSION 3.10)

# Set the project name
project(EPS_MODEL)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directory to ./build
set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)

# Add main.cpp as an executable target
add_executable(${PROJECT_NAME} main.cpp)

# Include headers
target_include_directories(${PROJECT_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/headers  # Aggiunto il percorso generale
    ${PROJECT_SOURCE_DIR}/headers/entities/geometry
    ${PROJECT_SOURCE_DIR}/headers/entities/physical
    
    ${PROJECT_SOURCE_DIR}/src/entities/geometry
    ${PROJECT_SOURCE_DIR}/src/entities/physical
    ${PROJECT_SOURCE_DIR}/src/logic/ordinamentoPacchi
    ${PROJECT_SOURCE_DIR}/src/logic/ottimizzazione
    ${PROJECT_SOURCE_DIR}/src/logic/sceltaPacchiNesting
    ${PROJECT_SOURCE_DIR}/src/logic/spostaPacchi
    ${PROJECT_SOURCE_DIR}/src/logic/trovaDominio
    ${PROJECT_SOURCE_DIR}/extLibs/nlohmannJSON
)

# Add source files to the executable target
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
