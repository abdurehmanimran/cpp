#include "shaders.hpp"
#include "glad/gl.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Shaders::Shaders(const std::string &vertexPath,
                 const std::string &fragmentPath) {
  vertexSource = readShader(vertexPath);
  fragmentSource = readShader(fragmentPath);

  vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource);
  fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

  createProgram();
}

std::string Shaders::readShader(const std::string &path) {
  std::string lineBuff;
  std::stringstream content;
  std::ifstream shaderStream(path);

  while (std::getline(shaderStream, lineBuff)) {
    content << lineBuff << "\n";
  }

  return content.str();
}

uint Shaders::compileShader(uint type, const std::string &src) {
  uint shader = glCreateShader(type);
  const char *source = src.c_str();
  glShaderSource(shader, 1, &source, nullptr);
  glCompileShader(shader);

  int status;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

  if (!status) {
    std::cout << "Error: failed to compile the "
              << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
              << " shader !!\n";
    exit(1);
  }

  return shader;
}

void Shaders::createProgram() {
  uint program = glCreateProgram();
  glAttachShader(program, vertexShader);
  glAttachShader(program, fragmentShader);

  glLinkProgram(program);

  shaderProgram = program;
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void Shaders::useProgram() const { glUseProgram(shaderProgram); }
