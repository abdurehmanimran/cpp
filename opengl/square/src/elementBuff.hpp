#pragma once
#include "glad/gl.h"

typedef unsigned int uint;

class EBO {
public:
  EBO(void *indexes, uint size);

  void bind() const;
  void unbind() const;

private:
  uint glId;
};
