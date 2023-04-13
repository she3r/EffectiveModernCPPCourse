#cmake_minimum_required(VERSION 3.16)
#project(EffectiveModernCPPCourse)
#
#set(CMAKE_CXX_STANDARD 20)
#
#set(Boost_INCLUDE_DIR "C:/Program\ Files/Boost/boost_1_81_0/")
##set(Boost_LIBRARY_DIR "C:/Program\ Files/Boost/boost_1_81_0/libs")
##find_package(Boost COMPONENTS system filesystem REQUIRED)
##include_directories(${Boost_INCLUDE_DIR})
#
#FIND_PACKAGE(Boost)
#IF (BOOST_FOUND)
#    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
#    ADD_DEFINITIONS( "-DHAS_BOOST" )
#ENDIF()
#
##add_executable(Fifth fifth/ex3_dynamicVector.cpp "fifth/staticVector.h" "fifth/dynamicVector.h")
#add_executable(5_ex4 fifth/ex4_conversion.cpp "fifth/staticVector.h" "fifth/dynamicVector.h")
#add_executable(6_ex1 6/ex1_variadicFunctions.cpp)
#add_executable(6_ex2 6/ex2_proxy.cpp)
#add_executable(6_ex3 6/ex3_Mixins.cpp)
#add_executable(6_ex4 6/ex4_MultiVector.cpp)

cmake_minimum_required(VERSION 3.16)
project(EffectiveModernCPPCourse)
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -pedantic -Werror)

add_executable(Range 7/ex_7_1_Range.cpp 7/Range.h)
add_executable(MatrixModifiers 7/ex_7_2_MatrixModifiers.cpp 7/Matrix.h )
add_executable(MatrixIterator 7/ex_7_3_MatrixIterator.cpp 7/Matrix.h )
add_executable(Filter 7/ex_7_4_Filter.cpp 7/Filter.h)

