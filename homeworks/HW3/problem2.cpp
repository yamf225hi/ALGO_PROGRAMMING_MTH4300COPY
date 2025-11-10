#include <iostream>
#include <iomanip>

// =====================================================================================
// This section is what would typically be in the "Matrix33.h" file.
// It contains the declaration of the Matrix33 class.
// =====================================================================================
class Matrix33 {
private:
    double matrix[3][3];

public:
    // Default constructor
    Matrix33();

    // Constructor that takes a 2D array
    Matrix33(double arr[3][3]);

    // Function to calculate the determinant
    double determinant() const;

    // Overloaded operators
    Matrix33 operator+(const Matrix33& other) const;
    Matrix33 operator*(const Matrix33& other) const;
    Matrix33 operator*(double scalar) const;

    // Friend functions for stream operators
    friend std::ostream& operator<<(std::ostream& os, const Matrix33& m);
    friend std::istream& operator>>(std::istream& is, Matrix33& m);
};

// =====================================================================================
// This section is what would typically be in the "Matrix33.cpp" file.
// It contains the implementation of the methods declared in the Matrix33 class.
// =====================================================================================

// Default constructor implementation
Matrix33::Matrix33() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = 0;
        }
    }
}

// Constructor that takes a 2D array implementation
Matrix33::Matrix33(double arr[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = arr[i][j];
        }
    }
}

// Determinant function implementation
double Matrix33::determinant() const {
    double det = 0;
    det += matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]);
    det -= matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
    det += matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
    return det;
}

// Overloaded + operator for matrix addition
Matrix33 Matrix33::operator+(const Matrix33& other) const {
    Matrix33 result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

// Overloaded * operator for matrix multiplication
Matrix33 Matrix33::operator*(const Matrix33& other) const {
    Matrix33 result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}

// Overloaded * operator for scalar multiplication
Matrix33 Matrix33::operator*(double scalar) const {
    Matrix33 result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.matrix[i][j] = matrix[i][j] * scalar;
        }
    }
    return result;
}

// Overloaded << operator to print the matrix
std::ostream& operator<<(std::ostream& os, const Matrix33& m) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            os << std::setw(8) << std::fixed << std::setprecision(2) << m.matrix[i][j];
        }
        os << std::endl;
    }
    return os;
}

// Overloaded >> operator to prompt user for matrix values
std::istream& operator>>(std::istream& is, Matrix33& m) {
    std::cout << "Enter 9 consecutive values for the 3x3 matrix:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            is >> m.matrix[i][j];
        }
    }
    return is;
}

// =====================================================================================
// This section is what would typically be in the "main.cpp" file.
// It contains the main function, which is the entry point of the program.
// =====================================================================================
int main() {
    Matrix33 m1;
    std::cin >> m1;

    std::cout << "\nMatrix m1:" << std::endl;
    std::cout << m1 << std::endl;

    double arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix33 m2(arr);

    std::cout << "Matrix m2:" << std::endl;
    std::cout << m2 << std::endl;

    Matrix33 m3 = m1 + m2;
    std::cout << "Matrix m3 = m1 + m2:" << std::endl;
    std::cout << m3 << std::endl;

    Matrix33 m4 = m1 * m2;
    std::cout << "Matrix m4 = m1 * m2:" << std::endl;
    std::cout << m4 << std::endl;

    Matrix33 m5 = m1 * 2.5;
    std::cout << "Matrix m5 = m1 * 2.5:" << std::endl;
    std::cout << m5 << std::endl;

    std::cout << "Determinant of m1: " << m1.determinant() << std::endl;
    std::cout << "Determinant of m2: " << m2.determinant() << std::endl;

    return 0;
}
