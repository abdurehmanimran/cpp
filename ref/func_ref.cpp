#include <array>
#include <iostream>

void printArr(const std::array<int, 10> &arr) {
  for (auto &number : arr)
    std::cout << number << std::endl;
}

void doubleArr(std::array<int, 10> &arr) {
  for (auto &number : arr)
    number *= 2;
}

int main() {
  std::array<int, 10> myArr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  printArr(myArr);
  doubleArr(myArr);
  printArr(myArr);
  return 0;
}
