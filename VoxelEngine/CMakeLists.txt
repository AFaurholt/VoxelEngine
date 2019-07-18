cmake_minimum_required(VERSION 3.13.4)

project(VoxelEngine)

# The version number.
set (VoxelEngine_VERSION_MAJOR 0)
set (VoxelEngine_VERSION_MINOR 0)
set (VoxelEngine_VERSION_PATCH 1)
set (VoxelEngine_VERSION_TWEAK 3)

# Select compiler and standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

IF (WIN32)
	
ELSE()
  set(CMAKE_CXX_COMPILER /usr/bin/c++)
ENDIF()

# Sub-dirs
add_subdirectory(src)

# Add source to this project's executable.
add_executable (VoxelEngine VoxelEngine.cpp)

# Link libs
target_link_libraries(VoxelEngine VoxelEngine-src)

# Download and unpack glfw at configure time
configure_file(CMakeLists.txt.in.glfw glfw-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/glfw-download )
if(result)
  message(FATAL_ERROR "CMake step for glfw failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/glfw-download )
if(result)
  message(FATAL_ERROR "Build step for glfw failed: ${result}")
endif()

# Add glfw directly to our build.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/glfw-src
                 ${CMAKE_CURRENT_BINARY_DIR}/glfw-build
                 EXCLUDE_FROM_ALL)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in.gtest googletest-download/CMakeLists.txt)
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

# Add tests to build and link libs
add_subdirectory(tests)
target_link_libraries(VoxelEngine-tests VoxelEngine-src gtest_main)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/ProjectConfig.h.in"
  "${PROJECT_BINARY_DIR}/ProjectConfig.h"
  )

# add the binary tree to the search path for include files
include_directories("${PROJECT_BINARY_DIR}")

#get_cmake_property(_variableNames VARIABLES)
#list (SORT _variableNames)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()