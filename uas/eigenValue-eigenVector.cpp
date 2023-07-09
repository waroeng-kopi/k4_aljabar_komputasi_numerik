#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void eigen(const vector<vector<int>>& matrix, vector<double>& eigenvalues, vector<vector<double>>& eigenvectors) {
  unsigned int n = matrix.size();

  // Create an identity matrix of the same dimension as the input matrix
  vector<vector<double>> identity(n, vector<double>(n, 0.0));
  for (unsigned int i = 0; i < n; ++i) {
    identity[i][i] = 1.0;
  }

  // Convert the input matrix to a double precision matrix
  vector<vector<double>> doubleMatrix(n, vector<double>(n, 0.0));
  for (unsigned int i = 0; i < n; ++i) {
    for (unsigned int j = 0; j < n; ++j) {
      doubleMatrix[i][j] = static_cast<double>(matrix[i][j]);
    }
  }

  // Perform the power iteration method
  unsigned int maxIterations = 100;
  double epsilon = 1e-8;

  eigenvectors = identity;  // Initial guess for eigenvectors

  for (unsigned int iteration = 0; iteration < maxIterations; ++iteration) {
    // Multiply the matrix with the eigenvectors
    vector<vector<double>> multipliedMatrix(n, vector<double>(n, 0.0));
    for (unsigned int i = 0; i < n; ++i) {
      for (unsigned int j = 0; j < n; ++j) {
        for (unsigned int k = 0; k < n; ++k) {
          multipliedMatrix[i][j] += doubleMatrix[i][k] * eigenvectors[k][j];
        }
      }
    }

    // Find the maximum element of the multiplied matrix
    double maxElement = 0.0;
    for (unsigned int i = 0; i < n; ++i) {
      for (unsigned int j = 0; j < n; ++j) {
        maxElement = max(maxElement, abs(multipliedMatrix[i][j]));
      }
    }

    // Divide the multiplied matrix by the maximum element
    for (unsigned int i = 0; i < n; ++i) {
      for (unsigned int j = 0; j < n; ++j) {
        multipliedMatrix[i][j] /= maxElement;
      }
    }

    // Calculate the difference between the multiplied matrix and the eigenvectors
    vector<vector<double>> diff(n, vector<double>(n, 0.0));
    for (unsigned int i = 0; i < n; ++i) {
      for (unsigned int j = 0; j < n; ++j) {
        diff[i][j] = multipliedMatrix[i][j] - eigenvectors[i][j];
      }
    }

    // Check if the difference is within the desired epsilon
    double diffNorm = 0.0;
    for (unsigned int i = 0; i < n; ++i) {
      for (unsigned int j = 0; j < n; ++j) {
        diffNorm += diff[i][j] * diff[i][j];
      }
    }
    diffNorm = sqrt(diffNorm);

    if (diffNorm < epsilon) {
      break;  // Converged, exit the loop
    }

    eigenvectors = multipliedMatrix;  // Update the eigenvectors for the next iteration
  }

  // Calculate eigenvalues from the final eigenvectors
  eigenvalues.resize(n);
  for (unsigned int i = 0; i < n; ++i) {
    eigenvalues[i] = eigenvectors[i][i];
  }
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

  vector<double> eigenvalues;
  vector<vector<double>> eigenvectors;

  eigen(matrix, eigenvalues, eigenvectors);

  cout << endl << "Eigenvalues: ";
  for (double eigenvalue : eigenvalues) {
    cout << eigenvalue << " ";
  }
  cout << endl;

  cout << "Eigenvectors:" << endl;
  for (const auto& eigenvector : eigenvectors) {
    for (double element : eigenvector) {
      cout << element << " ";
    }
    cout << endl;
  }

  return 0;
}
