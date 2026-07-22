#include <array>
#include <iostream>
using namespace std;

int main() {
  array<int, 10> myArray;

  for (int i = 0; i < myArray.size() / 2; i++)
    myArray[i] = (i + 1) * 10;

  for (int i = 0; i < myArray.size(); i++)
    cout << myArray[i] << endl;

  return 0;
}
