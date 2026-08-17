#include <cstdint>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <sys/types.h>
#include <vector>

class Matrix;
double determinant(Matrix mat);

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

  Matrix subMat(uint64_t row, uint64_t col) {
    if (n == 1 || m == 1 || (n != m) || row >= n || col >= m)
      return *this;

    Matrix mat{n - 1, m - 1};
    uint r{0}, c{0};

    for (uint i = 0; i < n; i++) {
      if (i == row)
        continue;
      for (uint j = 0; j < m; j++) {
        if (j == col)
          continue;

        mat.data[r][c] = this->data[i][j];
        c++;
      }
      r++;
      c = 0;
    }

    return mat;
  }

  friend double determinant(Matrix mat);

  Matrix transpose() {
    Matrix mat{n, m};

    uint r{0}, c{0};

    for (uint row = 0; row < n; row++) {
      for (uint col = 0; col < m; col++) {
        mat.data[row][col] = this->data[r][c];
        r++;
      }
      c++;
      r = 0;
    }

    return mat;
  }

  Matrix adjoint() {
    Matrix mat{n, m};

    for (uint row = 0; row < n; row++)
      for (uint col = 0; col < m; col++) {
        int cofactor =
            ((row + col) % 2 ? -1 : 1) * determinant(this->subMat(row, col));

        mat.data[row][col] = cofactor;
      }

    return mat.transpose();
  }

  Matrix inverse() {
    int det = determinant(*this);

    if (det == 0)
      return *this;

    return (this->adjoint() / det);
  }

  friend std::ostream &operator<<(std::ostream &stream, const Matrix &mat) {
    stream << "Rows -> " << mat.data.size() << "\tCols -> "
           << mat.data[0].size() << std::endl;
    stream << "_______________________________" << std::endl;

    for (std::vector<double> row : mat.data) {
      for (double &num : row) {
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

  friend Matrix operator/(const Matrix &mat, const int &div) {
    Matrix finalMat{mat.n, mat.m};

    for (uint row = 0; row < mat.n; row++)
      for (uint col = 0; col < mat.m; col++) {
        finalMat.data[row][col] = mat.data[row][col] / div;
      }

    return finalMat;
  }

private:
  uint n{};
  uint m{};

  std::vector<std::vector<double>> data;

  void initData() {
    for (int i = 0; i < n; i++) {
      data.push_back(std::vector<double>(m, 0));
    }
  }
};

double determinant(Matrix mat) {
  if (mat.m != mat.n) {
    std::cout << "Error: determinant is only a property of square matrix !!"
              << std::endl;
    return 0.0;
  }

  if (mat.n == 2 && mat.m == 2)
    return (mat.data[0][0] * mat.data[1][1]) -
           (mat.data[0][1] * mat.data[1][0]);

  double det{0};

  for (int c = 0; c < mat.m; c++) {
    int sign = (c) % 2 ? -1 : 1; // Sign only depends on col cuz row is 0
    det += sign * mat.data[0][c] * determinant(mat.subMat(0, c));
  }

  return det;
}

int main() {
  Matrix mat{3, 3};
  mat.getFromUser();

  std::cout << mat << std::endl;

  std::cout << "\tInverse Matrix" << std::endl;
  std::cout << mat.inverse();

  return 0;
}
