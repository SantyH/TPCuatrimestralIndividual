cmake_minimum_required(VERSION 3.7)
project(TPCuatrimestralIndividual)

set(CMAKE_CXX_STANDARD 98)

set(EXERCISE4_SRC ClientHotel.c Receptionist.c Invoice.c Invoice.h Reservation.c Reservation.h Room.c Room.h)
add_library(exercise4 ${EXERCISE4_SRC})
add_executable(exercise4EXE MainExercise4.c)
target_link_libraries(exercise4EXE exercise4)
target_link_libraries(exercise4EXE structs)
target_link_libraries(exercise4EXE scannerUtil)

