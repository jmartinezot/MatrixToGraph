cmake_minimum_required(VERSION 2.4.6)

SET( CMAKE_CXX_COMPILER "/usr/bin/g++" )
SET(CMAKE_CXX_FLAGS "-std=c++11 -Wuninitialized -Wunused-function -Wunused-label -Wunused-value -Wunused-variable")

find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(src)

link_directories(/usr/lib)

add_executable (MatrixToGraph src/MatrixToGraph.cpp src/Utils.cpp)
 
target_link_libraries(MatrixToGraph boost_program_options) 


