cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -gdwarf-3 -Wall -pthread -g")

add_subdirectory(b_tree)
add_subdirectory(queue)
add_subdirectory(stack)
add_subdirectory(two_three_tree)
