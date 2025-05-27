cmake_minimum_required(VERSION 3.20)
project(AirWatcher)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Collect all source files from src/
file(GLOB_RECURSE SOURCES
        "src/*.cpp"
)

# Include header files
include_directories(
        include
        include/dataAccess
        include/models/sensors
        include/models/users
        include/console
)

# Define executable
add_executable(AirWatcher ${SOURCES})