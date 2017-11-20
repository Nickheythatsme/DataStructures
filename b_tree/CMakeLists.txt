set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -gdwarf-3 -Wall -g")
project(b_tree)
set(SOURCES main.cpp test_o.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
