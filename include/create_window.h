#ifndef CREATE_WINDOW_H_
#define CREATE_WINDWO_H_

#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* create_window(int width, int height);

#endif