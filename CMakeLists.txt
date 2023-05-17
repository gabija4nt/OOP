cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(v2.0 VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the build type to Release
set(CMAKE_BUILD_TYPE "Release")

# Add the executable
add_executable(main test.cpp main.cpp studentas.cpp funkcijos.cpp)

# Specify the optimization level
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# Include the Catch library
add_subdirectory(Catch2-devel/Catch2-devel)

# Link the Catch library to your executable
target_link_libraries(main PRIVATE Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(main)

# Set the output directory for the executable
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/Release
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_BINARY_DIR}/Release
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR}/Release
)