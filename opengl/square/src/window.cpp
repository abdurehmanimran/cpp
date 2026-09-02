#include "window.hpp"

Window::Window(int w, int h,
               void(callbackFunc)(GLFWwindow *window, int width, int height))
    : width{w}, height{h} {
  window = setUpWindow(w, h, callbackFunc);
};

GLFWwindow *Window::setUpWindow(int w, int h,
                                void(callbackFunc)(GLFWwindow *window,
                                                   int width, int height)) {
  glfwInit();
  glfwWindowHint(GLFW_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_VERSION_MINOR, 3);

  GLFWwindow *window = glfwCreateWindow(w, h, "Square", nullptr, nullptr);
  glfwMakeContextCurrent(window);

  gladLoaderLoadGL();
  glViewport(0, 0, w, h);
  glfwSetFramebufferSizeCallback(window, callbackFunc);

  return window;
}
