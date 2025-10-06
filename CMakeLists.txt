cmake_minimum_required(VERSION 3.10)
project(WalterInSanDiego)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add executable
add_executable(wisd main.cpp)

# Link SDL2
target_link_libraries(wisd ${SDL2_LIBRARIES})
