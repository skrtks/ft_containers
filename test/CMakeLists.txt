project(test)

set(CMAKE_CXX_STANDARD 11)
include_directories(../List ../srcs)
add_executable(test test.cpp Catch2.h catchMain.cpp)