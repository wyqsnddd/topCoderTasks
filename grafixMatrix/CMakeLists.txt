project(grafixMatrix)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

if( CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX )
 add_definitions("-g -fPIC  -Wall -std=gnu++0x  ")
# add_definitions("-std=gnu++0x -o4 ")
endif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)


#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(customUnionFind ${PROJECT_SOURCE_DIR}/src/customUnionFind.cpp ${PROJECT_SOURCE_DIR}/include/customUnionFind.h)

add_executable(test ${PROJECT_SOURCE_DIR}/src/testUnion.cpp)
target_link_libraries(test customUnionFind)
