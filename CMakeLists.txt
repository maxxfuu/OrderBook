cmake_minimum_required(VERSION 3.31)
project(MyProject CXX)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add the executable (assuming orderbook/main.cpp exists)
add_executable(orderbook ../main.cpp)

# Include directories for headers
target_include_directories(orderbook PRIVATE ${CMAKE_SOURCE_DIR})
