#include <iostream>

int main() {
  int a = 0;
  int &ref_a = a;

  std::cout << "Enter a number: ";
  std::cin >> ref_a;

  std::cout << ref_a << std::endl;
  return 0;
}
