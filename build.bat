cmake  -G "MinGW Makefiles" -DCMAKE_C_COMPILER="C:/mingw64/bin/gcc.exe" -DCMAKE_CXX_COMPILER="C:/mingw64/bin/g++.exe" -B build   %1 %2 %3 %4 %5 %6
cd build
ninja
