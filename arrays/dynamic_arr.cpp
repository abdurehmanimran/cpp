#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <stdexcept>

#define INIT_SIZE 32

class Array {
public:
  Array() : size{0}, cap{INIT_SIZE} {
    arr = (int *)malloc(sizeof(int) * INIT_SIZE);
    memset(arr, 0, sizeof(int) * INIT_SIZE);
  };

  ~Array() {
    if (arr)
      free(arr);
  }

  int &operator[](size_t index) const {
    if (index >= cap || index < 0)
      throw std::out_of_range{"You cannot access out of the array!!"};

    return arr[index];
  }

  friend std::ostream &operator<<(std::ostream &stream, const Array &arr) {
    stream << "Size -> " << arr.size << "\t" << "Cap -> " << arr.cap
           << std::endl;

    for (size_t i = 0; i < arr.size; i++) {
      try {
        stream << "[" << i << "] : " << arr[i] << std::endl;
      } catch (std::out_of_range err) {
        std::cerr << err.what() << std::endl;
      }
    }

    return stream;
  }

  void insert(int element) {
    while (size + 1 > cap)
      expand(8);

    arr[size] = element;
    size++;
  }

  void pop() { size--; }

private:
  uint64_t size{0};
  uint64_t cap{0};
  int *arr = nullptr;

  void expand(size_t extraSize) {
    cap += extraSize;
    int *temp = (int *)realloc(arr, sizeof(int) * cap);

    if (temp == nullptr)
      throw std::bad_alloc{};
    else {
      arr = temp;
    }
  }
};

int main() {
  Array arr;

  int i = 0;

  while (i <= 100) {
    arr.insert(i);
    i++;
  }

  std::cout << arr;

  return 0;
}
