#include <iostream>
#include <istream>
#include <limits>
#include <ostream>

class Vec3 {
public:
  Vec3() : arr{} {};
  Vec3(int a, int b, int c) : arr{a, b, c} {};

  friend std::ostream &operator<<(std::ostream &stream, const Vec3 &vec) {
    stream << "[" << vec[0] << " " << vec[1] << " " << vec[2] << "]";
    return stream;
  }

  friend std::istream &operator>>(std::istream &stream, Vec3 &vec) {
    // Format -> [a b c]
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '[');
    stream >> vec[0];
    stream.ignore();
    stream >> vec[1];
    stream.ignore();
    stream >> vec[2];
    stream.ignore();

    return stream;
  }

  friend Vec3 operator+(const Vec3 &vec1, const Vec3 &vec2) {
    int a = vec1[0] + vec2[0];
    int b = vec1[1] + vec2[1];
    int c = vec1[2] + vec2[2];
    return Vec3(a, b, c);
  }

  friend Vec3 operator-(const Vec3 &vec) {
    return Vec3(vec[0] * -1, vec[1] * -1, vec[2] * -1);
  }

  friend Vec3 operator-(const Vec3 &vec1, const Vec3 &vec2) {
    return vec1 + (-vec2);
  }

  const int &operator[](size_t index) const { return arr[index]; }
  int &operator[](size_t index) { return arr[index]; }

private:
  int arr[3];
};

int main() {
  Vec3 vector1;
  Vec3 vector2;
  std::cout << "Enter the first vector: (Format -> [a b c])" << std::endl;
  std::cin >> vector1;

  std::cout << "Enter the second vector: (Format -> [a b c])" << std::endl;
  std::cin >> vector2;

  std::cout << "___________SUM_________________" << std::endl;
  std::cout << vector1 + vector2 << std::endl;
  std::cout << "_______________________________" << std::endl;

  std::cout << "__________DIFFERENCE___________" << std::endl;
  std::cout << vector1 - vector2 << std::endl;
  std::cout << "_______________________________" << std::endl;
  return 0;
}
