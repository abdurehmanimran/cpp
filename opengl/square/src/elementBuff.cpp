#include "elementBuff.hpp"

EBO::EBO(void *indexes, uint size) {
  glGenBuffers(1, &glId);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glId);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indexes, GL_STATIC_DRAW);
};

void EBO::bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glId); }
void EBO::unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
