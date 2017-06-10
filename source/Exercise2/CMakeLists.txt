cmake_minimum_required(VERSION 3.7)
project(TPCuatrimestralIndividual)

set(CMAKE_CXX_STANDARD 98)

set(EXERCISE2_SRC  Product.c Product.h RegisterUser.c RegisterUser.h Administrator.c Administrator.h PersonShop.c PersonShop.h Camera.c Camera.h Manufacturer.c Manufacturer.h Provider.c Provider.h Sale.c Sale.h SaleLine.c SaleLine.h Accessory.c Accessory.h)
add_library(exercise2 ${EXERCISE2_SRC})
add_executable(exercise2EXE MainExercise2.c)
target_link_libraries(exercise2EXE exercise2)
target_link_libraries(exercise2EXE structs)
target_link_libraries(exercise2EXE scannerUtil)

