#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string hello = "This is a string with some spaces !!";
  istringstream stream(hello);

  for (string token; getline(stream, token, ' ');) {
    cout << token << endl;
  }

  return 0;
}
