cmake_minimum_required(VERSION 3.17)
project(ft_containers)

add_subdirectory(test)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-pedantic -std=c++98 -Wall -Werror -Wextra")

add_executable(ft_containers srcs/main.cpp List/List.hpp List/ListNode.hpp)