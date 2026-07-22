#include <array>
#include <iostream>

int main() {
  int number{};

  std::cout << "Enter a number: ";
  std::cin >> number;

  std::array<std::array<int, 3>, 10> arr;

  for (int i = 0; i < arr.size(); i++) {
    arr[i][0] = number;
    arr[i][1] = i + 1;
    arr[i][2] = arr[i][0] * arr[i][1];
  }

  for (int i = 0; i < arr.size(); i++)
    printf("%d * %d == %d\n", arr[i][0], arr[i][1], arr[i][2]);

  return 0;
}
