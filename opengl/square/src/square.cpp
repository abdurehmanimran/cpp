#include "elementBuff.hpp"
#include "glad/gl.h"
#include "shaders.hpp"
#include "vertexArray.hpp"
#include "vertexBuff.hpp"
#include "window.hpp"

#include <GLFW/glfw3.h>
#include <string>

static void updateGLViewPort(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

int main() {
  Window MainWindow(800, 600, updateGLViewPort);
  Shaders shaderProgram("res/shaders/vertex.glsl", "res/shaders/fragment.glsl");

  float positions[] = {// 1st (Bottom Left)
                       -0.5f, -0.5f, 0.6, 1.0, 0.6,
                       // 2nd (Top Left)
                       -0.5f, 0.5f, 1.0, 0.6, 0.6,
                       // 3rd (Top Right)
                       0.5f, 0.5f, 0.6, 0.6, 1.0,
                       // 4th (Bottom Right)
                       0.5f, -0.5f, 1.0, 1.0, 1.0};

  uint indices[] = {// 1st Triangle
                    0, 1, 2,
                    // 2nd Triangle
                    0, 3, 2};

  VertexArray vertexArr;
  vertexArr.bind(); // Binding to record comming calls

  VBO vertexBuff(positions, sizeof(positions));
  EBO elementBuff(indices, sizeof(indices));

  vertexArr.addElement(2); // coords
  vertexArr.addElement(3); // color
  vertexArr.activateLayouts();

  vertexArr.unbind();
  shaderProgram.useProgram();

  while (!glfwWindowShouldClose(MainWindow.window)) {
    glfwPollEvents();

    vertexArr.bind();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    vertexArr.unbind();

    glfwSwapBuffers(MainWindow.window);
  }

  glfwTerminate();

  return 0;
}
