#include <fmt/core.h>

template <typename T> T add2(T input) { return input + 2; }

int main() {

  fmt::print("{:d}\n", add2(2));
  fmt::print("{}\n", add2('c'));
  fmt::print("{:f}\n", add2(5 / 2.0));

  return 0;
}
