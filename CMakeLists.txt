cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(v1.0.1.1 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(main main.cpp mix.cpp random.cpp files.cpp sort1.cpp)

# specify the optimization level
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")