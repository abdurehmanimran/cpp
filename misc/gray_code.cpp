#include <cmath>
#include <fmt/ranges.h>
#include <vector>

using namespace std;

vector<int> returnGrayCodes(int n) {
  vector<int> codes(n);

  codes[0] = 0;
  codes[1] = 1;

  int m = 2;
  int index = 2;

  while (index < n) {
    for (int i = 0; i < m; i++) {
      if (index >= n)
        break;

      int pos = log2(m);

      // Mirroring the end digits (least-sig figs)
      // & attaching a one to their left side
      // (~(unsigned int)0) >> (32 - pos) -> gives a number for bit masking
      // e.g 00000011, 00001111, etc. (This is now removed, was in my initial
      // thought process `_`).
      // codes[(2 * m - index - 1)] -> the prev gray code which
      // has to be

      int number = ((unsigned)1 << pos) + ((codes[(2 * m - index - 1)]));
      codes[index++] = number;
    }
    m *= 2;
  }

  return codes;
}

int main(int argc, char **argv) {
  if (argc <= 1)
    return 1;

  vector<int> code = returnGrayCodes(pow(2, atoi(argv[1])));

  for (int &num : code)
    fmt::print("{:<5d} {:>10b}\n", num, num);

  return 0;
}
