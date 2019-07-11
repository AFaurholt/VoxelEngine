# CMakeList.txt : CMake project for VoxelEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)
IF (WIN32)
  set(CMAKE_CXX_COMPILER MSVC_VERSION)
ELSE()
  set(CMAKE_CXX_COMPILER /usr/bin/g++)
ENDIF()
# Add source to this project's executable.
add_executable (VoxelEngine "VoxelEngine.cpp" "VoxelEngine.h")

# TODO: Add tests and install targets if needed.
