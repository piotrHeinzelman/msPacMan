cmake_minimum_required(VERSION 3.26)
project(msPacMan)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(msPacMan main.cpp
)


# example library
add_library(sum_integers sum_integers.cpp)

# main code
#add_executable(msPacMan main.cpp)
target_link_libraries(msPacMan PRIVATE sum_integers)

# testing binary
add_executable(cpp_test test.cpp)
target_link_libraries(cpp_test PRIVATE sum_integers)

# enable testing functionality
enable_testing()

# define tests
add_test(
        NAME cpp_test
        COMMAND $<TARGET_FILE:cpp_test>
)