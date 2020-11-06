cmake_minimum_required(VERSION 3.17)
project(ft_containers)

add_subdirectory(test)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-pedantic -std=c++98 -Wall -Werror -Wextra")
include_directories(srcs srcs/list srcs/vector srcs/stack srcs/queue srcs/map)

add_executable(ft_containers srcs/main.cpp srcs/list/list.hpp srcs/list/listNode.hpp srcs/list/BidirectionalIterator.hpp srcs/Traits.hpp srcs/vector/vector.hpp srcs/vector/RandomAccessIterator.hpp srcs/stack/stack.hpp srcs/queue/queue.hpp srcs/map/map.hpp srcs/map/mapNode.hpp)