cmake_minimum_required(VERSION 3.7)
project(TPCuatrimestralIndividual)

set(CMAKE_CXX_STANDARD 98)

set(EXERCISE3_SRC Book.c Library.c Loan.c Magazine.c Material.c Person.c Student.c Teacher.c)
add_library(exercise3 ${EXERCISE3_SRC})
add_executable(exercise3EXE MainExercise3.c)
target_link_libraries(exercise3EXE exercise3)

