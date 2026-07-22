#include <iostream>
#include <ostream>

class QuadraticEq {
public:
  // Constructor
  QuadraticEq() {};
  QuadraticEq(int alpha, int beta, int charlie)
      : a{alpha}, b{beta}, c{charlie} {};

  // Public Funcs
  void getFromUser();
  double determinant() const;
  std::string toString() const;
  double solve() const;

  friend QuadraticEq operator+(const QuadraticEq &eq1, const QuadraticEq &eq2);
  friend std::ostream &operator<<(std::ostream &, const QuadraticEq &equation);

private:
  int a{0};
  int b{0};
  int c{0};
};

QuadraticEq operator+(const QuadraticEq &eq1, const QuadraticEq &eq2) {
  return QuadraticEq{eq1.a + eq2.a, eq1.b + eq2.b, eq1.c + eq2.c};
}

std::ostream &operator<<(std::ostream &stream, const QuadraticEq &equation) {
  stream << ":: -> " << equation.a << "x2 ";
  if (equation.b >= 0)
    stream << "+";

  stream << equation.b << "x ";

  if (equation.c >= 0)
    stream << "+";

  stream << equation.c;
  return stream;
}

void QuadraticEq::getFromUser() {
  std::cout << "Enter the roots of the equation !!" << std::endl;
  std::cout << "Alpha : ";
  std::cin >> a;

  std::cout << "Beta: ";
  std::cin >> b;

  std::cout << "Charlie: ";
  std::cin >> c;
}

double QuadraticEq::determinant() const { return (b * b) - (4 * (a * c)); }

int main() {
  QuadraticEq eq1;
  eq1.getFromUser();

  QuadraticEq eq2;
  eq2.getFromUser();

  std::cout << eq1 + eq2 << std ::endl;
  std::cout << eq2 << std ::endl;
  // std::cout << eq1.determinant();

  return 0;
}
