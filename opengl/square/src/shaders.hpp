#pragma once
#include "glad/gl.h"

#include <string>

class Shaders {
public:
  Shaders(const std::string &vertexPath, const std::string &fragmentPath);
  void useProgram() const;

private:
  std::string vertexSource;
  std::string fragmentSource;

  uint vertexShader;
  uint fragmentShader;

  uint shaderProgram;

  std::string readShader(const std::string &path);
  uint compileShader(uint type, const std::string &src);
  void createProgram();
};
