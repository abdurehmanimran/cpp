#include <iostream>
#include <ostream>
#include <stdexcept>
#include <vector>

class Matrix {
public:
  Matrix() : n{0}, m{0} {};

  Matrix(uint rowCount, uint colCount) : n{rowCount}, m{colCount} {
    initData();
  };

  void getFromUser() {
    if (n == 0 || m == 0) {
      std::cout << "Enter the dimensions of the matrix !!" << std::endl;
      std::cout << "Rows:";
      std::cin >> n;

      std::cout << "Columns:";
      std::cin >> m;

      initData();
    }

    std::cout << "Input values for the matrix !!" << std::endl;

    for (uint i = 0; i < n; i++) {
      for (uint j = 0; j < m; j++) {
        std::cout << "[" << i << "] [" << j << "] : ";
        std::cin >> data[i][j];
      }
    }
  }

  friend std::ostream &operator<<(std::ostream &stream, const Matrix &mat) {
    stream << "Rows -> " << mat.data.size() << "\tCols -> "
           << mat.data[0].size() << std::endl;
    stream << "_______________________________" << std::endl;

    for (std::vector<int> row : mat.data) {
      for (int &num : row) {
        stream << num << " ";
      }
      stream << std::endl;
    }
    stream << "_______________________________" << std::endl;

    return stream;
  }

  friend Matrix operator+(const Matrix &mat1, const Matrix &mat2) {
    Matrix m;

    if (mat1.m != mat2.m || mat1.n != mat2.n)
      throw std::runtime_error{
          "You cannot add two matrices with different dimensions !!"};

    m.n = mat1.n;
    m.m = mat1.m;

    m.initData();

    for (uint i = 0; i < m.n; i++)
      for (uint j = 0; j < m.m; j++) {
        m.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
      }

    return m;
  }

  friend Matrix operator-(const Matrix &mat) {
    Matrix m{mat.n, mat.m};

    for (uint i = 0; i < m.n; i++)
      for (uint j = 0; j < m.m; j++) {
        m.data[i][j] = -mat.data[i][j];
      }

    return m;
  }

  friend Matrix operator-(const Matrix &mat1, const Matrix &mat2) {
    if (mat1.m != mat2.m || mat1.n != mat2.n)
      throw std::runtime_error{
          "You cannot add subtract matrices with different dimensions !!"};

    return mat1 + (-mat2);
  }

  friend Matrix operator*(const Matrix &mat1, const Matrix &mat2) {

    if (mat1.m != mat2.n)
      throw std::runtime_error{"You cannot multiply these two matrices !!"};

    Matrix m{mat1.m, mat2.n};

    for (int i = 0; i < m.n; i++) {
      for (int j = 0; j < m.m; j++) {
        int sum = 0;

        for (int x = 0; x < mat1.m; x++)
          sum += mat1.data[i][x] * mat2.data[x][j];

        m.data[i][j] = sum;
      }
    }

    return m;
  }

private:
  uint n{};
  uint m{};

  std::vector<std::vector<int>> data;

  void initData() {
    for (int i = 0; i < n; i++) {
      data.push_back(std::vector<int>(m, 0));
    }
  }
};

int main() {
  Matrix mat{2, 3};
  mat.getFromUser();

  Matrix mat2{2, 2};
  mat2.getFromUser();

  Matrix result;
  // try {
  //   result = mat + mat2;
  // } catch (std::runtime_error err) {
  //   std::cout << "Error: " << err.what() << std::endl;
  //   return 1;
  // }

  std::cout << mat;
  std::cout << mat2;
  // std::cout << result;
  std::cout << mat - mat2;
  std::cout << "_________Product Matrix___________" << std::endl;
  std::cout << mat * mat2;

  return 0;
}
