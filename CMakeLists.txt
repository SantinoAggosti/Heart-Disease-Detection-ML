# CMakeList.txt : CMake project for Level3Eda-HeartDiseaseDetection, include source and define
# project specific logic here.
#

cmake_minimum_required(VERSION 3.0.0)

project(main)

set(CMAKE_CXX_STANDARD 11)

# Add source to this project's executable.
add_executable (main main.cpp  CSVData.cpp )


# TODO: Add tests and install targets if needed.

