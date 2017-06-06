cmake_minimum_required(VERSION 3.7)
project(TPCuatrimestralIndividual)

set(CMAKE_CXX_STANDARD 98)

set(EXERCISE2_SRC  Product.c Product.h Camera.c)
add_library(exercise2 ${EXERCISE2_SRC})
add_executable(exercise2EXE MainExercise2.c)
target_link_libraries(exercise2EXE exercise2)
target_link_libraries(exercise2EXE structs)
target_link_libraries(exercise2EXE scannerUtil)

