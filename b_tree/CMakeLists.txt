set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -gdwarf-3 -Wall -pthread -g")
project(b_tree)
set(SOURCES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
