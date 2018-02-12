cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DNDEBUG -gdwarf-3 -Wall -pthread -g")

add_subdirectory(trees)
add_subdirectory(graphs)
add_subdirectory(queue)
add_subdirectory(stack)
add_subdirectory(vector)
