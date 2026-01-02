cmake_minimum_required(VERSION 3.10)

project(program_2.6)

add_library(tools STATIC ../../../lib/tools/src/tools.cpp)
target_include_directories(tools PUBLIC ../../../lib/tools/include)


add_library(utils STATIC ../../../lib/utils/src/Utils.cpp)
target_include_directories(utils PUBLIC ../../../lib/utils/include)
target_include_directories(utils PUBLIC ../../../external/SOIL2/src/SOIL2)

find_package(glm CONFIG REQUIRED)
find_package(soil2 CONFIG REQUIRED)
target_link_libraries(utils PUBLIC glm::glm soil2)

add_executable(program_2.6 main.cpp)

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(program_2.6 glfw)

find_package(OpenGL REQUIRED)
target_link_libraries(program_2.6 OpenGL::GL)

find_package(GLEW REQUIRED)
target_link_libraries(program_2.6 GLEW::glew)

target_link_libraries(program_2.6 tools)
target_link_libraries(program_2.6 utils)
target_include_directories(program_2.6 PUBLIC ../../../lib/utils/include)
target_include_directories(program_2.6 PUBLIC ../../../external/SOIL2/src/SOIL2)