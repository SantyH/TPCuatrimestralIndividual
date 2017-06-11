cmake_minimum_required(VERSION 3.7)
project(TPCuatrimestralIndividual)

set(CMAKE_CXX_STANDARD 98)

set(EXERCISE1_SRC HouseElectro.c HouseElectro.h MainExercise1.c Label.c Label.h Provider.c Provider.h Catalog.c Catalog.h Maker.c Maker.h BagLine.c BagLine.h Bag.c Bag.h BillLine.c BillLine.h Bill.c Bill.h)
add_library(exercise1 ${EXERCISE1_SRC})
add_executable(exercise1EXE MainExercise1.c)
target_link_libraries(exercise1EXE exercise1)
target_link_libraries(exercise1EXE structs)
target_link_libraries(exercise1EXE scannerUtil)

