cmake_minimum_required(VERSION 3.7)
project(TPCuatrimestralIndividual)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp "source/Exercise 5/Client.c" "source/Exercise 5/Client.h" "source/Exercise 5/MovieCard.c" "source/Exercise 5/MovieCard.h" "source/Exercise 5/Movie.c" "source/Exercise 5/Movie.h" "source/Exercise 5/Manager.c" "source/Exercise 5/Manager.h" "source/Exercise 5/Excess.c" "source/Exercise 5/Excess.h" "source/Exercise 5/MovieClub.c" "source/Exercise 5/MovieClub.h")
add_executable(TPCuatrimestralIndividuaal ${SOURCE_FILES} "source/Exercise 5/Client.c" "source/Exercise 5/Client.h" "source/Exercise 5/MovieCard.c" "source/Exercise 5/MovieCard.h" "source/Exercise 5/Movie.c" "source/Exercise 5/Movie.h" "source/Exercise 5/Manager.c" "source/Exercise 5/Manager.h" "source/Exercise 5/Excess.c" "source/Exercise 5/Excess.h" "source/Exercise 5/MovieClub.c" "source/Exercise 5/MovieClub.h")
