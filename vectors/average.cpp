#include <iostream>
#include <vector>

int main() {
  std::vector<int> dynamic_arr;

  int n = 0;
  int sum = 0;
  printf("Enter the integers one by one !!\n");

  int status = scanf("%d", &n);

  while (status == 1) {
    dynamic_arr.push_back(n);
    status = scanf("%d", &n);
  }

  for (int num : dynamic_arr)
    sum += num;

  printf("Average -> %f\n", static_cast<double>(sum) / dynamic_arr.size());

  return 0;
}
