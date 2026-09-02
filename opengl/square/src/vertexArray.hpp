#pragma once

#include <vector>

typedef unsigned int uint;

struct buffElement {
  uint count;
  void *offset;
};

class VertexArray {
public:
  VertexArray();

  void setLayout(uint loc, uint count, uint stride, void *offset) const;
  void addElement(uint count);

  void activateLayouts();

  void bind() const;
  void unbind() const;

private:
  uint vertexArrID{};
  uint stride{};
  std::vector<buffElement> elements;
};
