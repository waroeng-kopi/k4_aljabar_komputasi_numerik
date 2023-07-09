#include <iostream>
#include <vector>

using namespace std;

// Function to print matrix
void printMatrix(const vector<vector<int>>& matrix) {
  for (const auto& row : matrix) {
    for (int element : row) {
      cout << element << " ";
    }
    cout << endl;
  }
}

// Function to calculate determinant of 2x2 matrix
int determinant2x2(const vector<vector<int>>& matrix) {
  return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
}

// Function to find submatrix
vector<vector<int>> submatrix(const vector<vector<int>>& matrix, unsigned int x, unsigned int y) {
  vector<vector<int>> submatrix;
  for (unsigned int i = 0; i < matrix.size(); ++i) {
    if (i == y) {
      continue;
    }
    vector<int> row;
    for (unsigned int j = 0; j < matrix.size(); ++j) {
      if (j == x) {
        continue;
      }
      row.push_back(matrix[i][j]);
    }
    submatrix.push_back(row);
  }
  return submatrix;
}

// Function to calculate determinant of matrix
int determinant(const vector<vector<int>>& matrix) {
  int n = matrix.size();
  if (n == 2) {
    return determinant2x2(matrix);
  }
  int det = 0;
  for (unsigned int x = 0; x < matrix.size(); ++x) {
    vector<vector<int>> sub = submatrix(matrix, x, 0);
    det += ((x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(sub));
  }
  return det;
}

// Function to find inverse matrix
bool inverseMatrix(const vector<vector<int>>& matrix, vector<vector<int>>& inverse) {
  int det = determinant(matrix);
  if (det == 0) {
    cout << "Matrix does not have an inverse." << endl;
    return false;
  }

  int n = matrix.size();
  inverse.resize(n, vector<int>(n));

  vector<vector<int>> cofactor(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      vector<vector<int>> sub = submatrix(matrix, j, i);
      cofactor[i][j] = ((i + j) % 2 == 0 ? 1 : -1) * determinant(sub);
    }
  }

  // Transpose the cofactor matrix
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      inverse[i][j] = cofactor[j][i];
    }
  }

  // Divide by the determinant
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      inverse[i][j] /= det;
    }
  }

  return true;
}

int main() {
  unsigned int n;
  cout << "Enter matrix dimension: ";
  cin >> n;

  vector<vector<int>> matrix(n, vector<int>(n));
  for (unsigned int j = 0; j < n; ++j) {
    for (unsigned int i = 0; i < n; ++i) {
      cin >> matrix[i][j];
    }
  }

  cout << endl;

  vector<vector<int>> inverse;
  if (inverseMatrix(matrix, inverse)) {
    cout << "Inverse matrix:" << endl;
    printMatrix(inverse);
  }

  return 0;
}
