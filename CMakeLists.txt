cmake_minimum_required(VERSION 3.21)
project(code)

set(CMAKE_CXX_STANDARD 17)
##set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCMAKE_EXPORT_COMPILE_COMMANDS=1")
##set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")

add_executable(meituan1 miscellaneous/meituan1.cpp)
add_executable(meituan4 miscellaneous/meituan4.cpp)
add_executable(meituan11 miscellaneous/meituan11.cpp)
add_executable(meituan3 miscellaneous/meituan3.cpp)
add_executable(meituan5 miscellaneous/meituan5.cpp)