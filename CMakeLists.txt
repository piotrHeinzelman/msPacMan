cmake_minimum_required(VERSION 3.26)
project(msPacMan)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -s -O3 -I C:/Users/Shiro/Desktop/asio-1.10.6/include")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -s -O3 ")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS} -static -lws2_32")

link_libraries(ws2_32 wsock32)



add_executable(msPacMan main.cpp

        src/Controllers/Controller.h
        src/Controllers/Controller.cpp
        src/Controllers/GhostAutoController.h
        src/Controllers/GhostAutoController.cpp
        src/Controllers/LocalKeyboardController.h
        src/Controllers/LocalKeyboardController.cpp
        src/Controllers/RemoteUDPController.h
        src/Controllers/RemoteUDPController.cpp


        src/UDPClient.cpp
        src/UDPClient.h
        src/UDPServ.cpp
        src/UDPServ.h

        src/Board.cpp
        src/Board.h
        src/ConsoleDraw.cpp
        src/ConsoleDraw.h
        src/Mob.cpp
        src/Mob.h
        src/DIRECT.h
        src/Bridges.cpp
        src/Bridges.h

        src/Dot.cpp
        src/Dot.h
        src/Bridge.h
        src/Bridge.cpp
        src/Ways.h
        src/Server.cpp
        src/Server.h
        tests/ServerTest.h


)

