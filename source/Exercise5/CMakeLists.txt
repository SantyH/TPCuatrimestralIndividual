cmake_minimum_required(VERSION 3.7)
project(TPCuatrimestralIndividual)

set(CMAKE_CXX_STANDARD 98)

set(EXERCISE5_SRC Client.c Excess.c Manager.c Movie.c MovieCard.c MovieClub.c)
add_library(exercise5 ${EXERCISE5_SRC})
add_executable(exe MainExercise5.c)
target_link_libraries(exe exercise5)
target_link_libraries(exe structs)

