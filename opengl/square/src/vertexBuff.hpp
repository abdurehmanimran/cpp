#pragma once
#include "glad/gl.h"

typedef unsigned int uint;

class VBO {
public:
  VBO(void *positions, uint size);

  void bind() const;
  void unbind() const;

private:
  uint glId;
};
