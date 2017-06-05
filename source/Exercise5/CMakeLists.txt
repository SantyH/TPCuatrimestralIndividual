cmake_minimum_required(VERSION 3.7)
project(TPCuatrimestralIndividual)

set(CMAKE_CXX_STANDARD 98)

set(EXERCISE5_SRC Excess.c Manager.c Movie.c MovieCard.c MovieClub.c MovieClub.h Movie.h Client.c Client.h)
add_library(exercise5 ${EXERCISE5_SRC})
add_executable(exercise5EXE MainExercise5.c)
target_link_libraries(exercise5EXE exercise5)

