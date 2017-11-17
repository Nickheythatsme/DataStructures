set(CMAKE_LEGACY_CYGWIN_WIN32 0) # Remove when CMake >= 2.8.4 is required
project(two_three_tree)
set(SOURCES main.cpp ../BST/node.cpp ../BST/node.h ../BST/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
