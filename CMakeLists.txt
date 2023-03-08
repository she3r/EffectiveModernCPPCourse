cmake_minimum_required(VERSION 3.16)
project(EffectiveModernCPPCourse)

set(CMAKE_CXX_STANDARD 17)

#add_executable(EffectiveModernCPPCourse Algos/Sortings.cpp Algos/binary_search.cpp)
add_executable(EffectiveModernCPPCourse matrix_test.cpp "first/Matrix.cpp")
add_executable(DynamicContainer second/Ex3_DynamicContainer.cpp)
add_executable(StaticContainer second/Ex1_StaticContainer.cpp)
add_executable(StaticContainer2 second/Ex2_StaticContainer2.cpp)

add_executable(String second/Ex4_String.cpp)
