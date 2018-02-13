set(CMAKE_LEGACY_CYGWIN_WIN32 0) # Remove when CMake >= 2.8.4 is required
project(stack)
set(SOURCES main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
