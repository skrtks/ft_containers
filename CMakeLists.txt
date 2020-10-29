cmake_minimum_required(VERSION 3.17)
project(ft_containers)

add_subdirectory(test)
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-pedantic -std=c++98 -Wall -Werror -Wextra")
include_directories(srcs list vector stack queue)

add_executable(ft_containers srcs/main.cpp List/list.hpp List/Node.hpp List/BidirectionalIterator.hpp srcs/Traits.hpp Vector/vector.hpp Vector/RandomAccessIterator.hpp Stack/stack.hpp queue/queue.hpp)