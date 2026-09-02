#pragma once
#include "glad/gl.h"

#include <GLFW/glfw3.h>

class Window {
public:
  Window(int w, int h,
         void(callbackFunc)(GLFWwindow *window, int width, int height));
  GLFWwindow *window{};

private:
  int height{};
  int width{};

  GLFWwindow *setUpWindow(int w, int h,
                          void(callbackFunc)(GLFWwindow *window, int width,
                                             int height));
};
