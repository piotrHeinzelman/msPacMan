cmake_minimum_required(VERSION 3.26)
project(xxx)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -s -O3 -I C:/Users/Shiro/Desktop/asio-1.10.6/include")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS} -static -lws2_32")

link_libraries(ws2_32 wsock32)


add_executable(
        xxx main.cpp
        comm.h
        comm.cpp

        tests/commTest.h
        tests/myTests.h
        )


