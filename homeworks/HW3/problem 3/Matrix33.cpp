#include "Matrix33.h"
#include <iostream>

// Default constructor
Matrix33::Matrix33() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = 0;
        }
    }
}

// Constructor that takes a 2D array
Matrix33::Matrix33(double arr[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = arr[i][j];
        }
    }
}

// Overload () operator to access elements
double& Matrix33::operator()(int row, int col) {
    return matrix[row][col];
}

const double& Matrix33::operator()(int row, int col) const {
    return matrix[row][col];
}

// Overload << operator to print the matrix
std::ostream& operator<<(std::ostream& os, const Matrix33& m) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            os << m(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

// Overload >> operator to read matrix values from user
std::istream& operator>>(std::istream& is, Matrix33& m) {
    std::cout << "Enter 9 values for the 3x3 matrix:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            is >> m(i, j);
        }
    }
    return is;
}
