cmake_minimum_required(VERSION 3.7)
project(TPCuatrimestralIndividual)

set(CMAKE_CXX_STANDARD 98)

set(EXERCISE5_SRC Client.c Excess.c Manager.c Movie.c MovieCard.c MovieClub.c MovieClub.h)
add_library(Exercise5 ${EXERCISE5_SRC})
add_executable(exe MainExercise5.c)
target_link_libraries(exe Client.c)
target_link_libraries(exe MovieClub.c)
target_link_libraries(exe Movie.c)
target_link_libraries(exe Manager.c)
target_link_libraries(exe Excess.c)
target_link_libraries(exe MovieCard.c)

