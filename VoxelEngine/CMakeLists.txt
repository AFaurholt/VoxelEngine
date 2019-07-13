# CMakeList.txt : CMake project for VoxelEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.14)

project(VoxelEngine)

# The version number.
set (VoxelEngine_VERSION_MAJOR 0)
set (VoxelEngine_VERSION_MINOR 0)
set (VoxelEngine_VERSION_PATCH 0)

# Select compiler and standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

IF (WIN32)
	
ELSE()
  set(CMAKE_CXX_COMPILER /usr/bin/g++)
ENDIF()

# Sub-dirs
add_subdirectory(src)

# Add source to this project's executable.
add_executable (VoxelEngine VoxelEngine.cpp)

# Link libs
target_link_libraries(VoxelEngine VoxelEngine-src)

# Add tests
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)