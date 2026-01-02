cmake_minimum_required(VERSION 3.10)

project(program_2.3)

add_library(tools STATIC ../../../lib/tools/src/tools.cpp)
target_include_directories(tools PUBLIC ../../../lib/tools/include)

add_executable(program_2.3 main.cpp)

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(program_2.3 glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(program_2.3 OpenGL::GL)

find_package(GLEW REQUIRED)
target_link_libraries(program_2.3 GLEW::glew)

target_link_libraries(program_2.3 tools)