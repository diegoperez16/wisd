cmake_minimum_required(VERSION 3.15)
project(wisd)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Platform-specific settings for raylib
if(NOT DEFINED PLATFORM)
    # Detect platform if not specified
    if(EMSCRIPTEN)
        set(PLATFORM "Web")
    elseif(UNIX AND NOT APPLE)
        set(PLATFORM "Desktop")
    elseif(APPLE)
        set(PLATFORM "Desktop")
    elseif(WIN32)
        set(PLATFORM "Desktop")
    endif()
endif()

# Find raylib
find_package(raylib 5.0 QUIET)

if (NOT raylib_FOUND)
    # Download raylib if not found
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.0
    )
    
    # Configure raylib options before fetching
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
    
    FetchContent_MakeAvailable(raylib)
endif()

# Set source files
set(SOURCES
    src/main.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link raylib
target_link_libraries(${PROJECT_NAME} raylib)

# Enable warnings
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

