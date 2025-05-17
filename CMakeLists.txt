# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(SoftwareUdvikling LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCES
    main.cpp
    Character.cpp
    Hero.cpp
    Enemy.cpp
    CombatManager.cpp
    Cave.cpp
    Weapon.cpp
)

# Add the header files (optional, for IDEs)
set(HEADERS
    Character.h
    Hero.h
    Enemy.h
    CombatManager.h
    Cave.h
    Weapon.h
)

# Create the executable
add_executable(game ${SOURCES} ${HEADERS})

# Include directories (if needed)
include_directories(${CMAKE_SOURCE_DIR})