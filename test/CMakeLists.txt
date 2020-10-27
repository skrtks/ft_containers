project(test)

set(CMAKE_CXX_STANDARD 11)
include_directories(../List ../srcs ../Vector)
add_executable(test listTest.cpp Catch2.h catchMain.cpp vectorTest.cpp)