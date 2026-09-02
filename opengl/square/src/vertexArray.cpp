#include "vertexArray.hpp"
#include "glad/gl.h"

VertexArray::VertexArray() { glGenVertexArrays(1, &vertexArrID); }

void VertexArray::setLayout(uint loc, uint count, uint stride,
                            void *offset) const {
  glEnableVertexAttribArray(loc);
  glVertexAttribPointer(loc, count, GL_FLOAT, GL_FALSE, stride, offset);
}

void VertexArray::addElement(uint count) {
  buffElement element{count, (void *)stride};
  stride += count * sizeof(float);

  elements.push_back(element);
}

void VertexArray::activateLayouts() {
  uint i{0};

  for (const buffElement &element : elements) {
    glEnableVertexAttribArray(i);
    glVertexAttribPointer(i, element.count, GL_FLOAT, GL_FALSE, stride,
                          element.offset);
    i++;
  }
}

void VertexArray::bind() const { glBindVertexArray(vertexArrID); }
void VertexArray::unbind() const { glBindVertexArray(0); }
