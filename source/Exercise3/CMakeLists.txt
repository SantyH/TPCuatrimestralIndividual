cmake_minimum_required(VERSION 3.7)
project(TPCuatrimestralIndividual)

set(CMAKE_CXX_STANDARD 98)

set(EXERCISE3_SRC Book.c Book.h Library.c Library.h Loan.c Loan.h Magazine.c Magazine.h Material.c Material.h Person.c Person.h Student.c Student.h Teacher.c Teacher.h)
add_library(exercise3 ${EXERCISE3_SRC})
add_executable(exercise3EXE MainExercise3.c)
target_link_libraries(exercise3EXE exercise3)
target_link_libraries(exercise3EXE structs)
target_link_libraries(exercise3EXE scannerUtil)

