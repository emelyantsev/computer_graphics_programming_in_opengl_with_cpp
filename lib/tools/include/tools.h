#pragma once

#include <GLFW/glfw3.h>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) ;

void updateFPS(GLFWwindow* window);

void framebuffer_size_callback(GLFWwindow* window, int width, int height) ;