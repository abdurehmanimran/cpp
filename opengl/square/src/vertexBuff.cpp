#include "vertexBuff.hpp"

VBO::VBO(void *positions, uint size) {
  glGenBuffers(1, &glId);
  glBindBuffer(GL_ARRAY_BUFFER, glId);
  glBufferData(GL_ARRAY_BUFFER, size, positions, GL_STATIC_DRAW);
};

void VBO::bind() const { glBindBuffer(GL_ARRAY_BUFFER, glId); }
void VBO::unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }
