cmake_minimum_required(VERSION 3.10)

project(program_2.1)

add_executable(program_2.1 main.cpp)

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(program_2.1 glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(program_2.1 OpenGL::GL)

find_package(GLEW REQUIRED)
target_link_libraries(program_2.1 GLEW::glew)