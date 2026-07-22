#include <array>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  array<int, 10> myArray;
  int sum{};

  cout << "Enter any 10 integers one by one!!" << endl;

  for (int i = 0; i < myArray.size(); i++) {
    cin >> myArray[i];
    sum += myArray[i];
  }

  cout << "______________________________________" << endl;
  for (int i = 0; i < myArray.size(); i++) {
    printf("%-5d : ", myArray[i]);
    // cout << myArray[i] << setw(5) << " : ";
    for (int y = 0; y < myArray[i]; y++)
      cout << "*";
    cout << endl;
  }
  cout << "______________________________________" << endl;

  return 0;
}
