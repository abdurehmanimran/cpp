#include <array>
#include <iostream>
using namespace std;

int main() {
  array<int, 10> myArray;
  int sum{};

  cout << "Enter any 10 integers one by one!!" << endl;

  for (int i = 0; i < myArray.size(); i++) {
    cin >> myArray[i];
    sum += myArray[i];
  }

  cout << "The average is: " << sum / myArray.size() << endl;

  return 0;
}
