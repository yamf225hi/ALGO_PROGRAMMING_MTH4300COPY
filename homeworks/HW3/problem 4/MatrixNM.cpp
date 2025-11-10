#include "MatrixNM.h"
#include <iomanip> // For std::setw, std::fixed, std::setprecision
#include <cmath>   // For std::abs (used in determinant calculation)

// Default constructor (creates a 0x0 matrix)
MatrixNM::MatrixNM() : rows_(0), cols_(0) {}

// Constructor with dimensions
MatrixNM::MatrixNM(size_t rows, size_t cols) : rows_(rows), cols_(cols) {
    if (rows_ == 0 || cols_ == 0) {
        // If either dimension is zero, create an empty matrix
        rows_ = 0;
        cols_ = 0;
    }
    matrix.resize(rows_);
    for (size_t i = 0; i < rows_; ++i) {
        matrix[i].resize(cols_, 0.0); // Initialize with 0.0
    }
}

// Overload () operator for element access
double& MatrixNM::operator()(size_t row, size_t col) {
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("MatrixNM: Index out of bounds");
    }
    return matrix[row][col];
}

const double& MatrixNM::operator()(size_t row, size_t col) const {
    if (row >= rows_ || col >= cols_) {
        throw std::out_of_range("MatrixNM: Index out of bounds");
    }
    return matrix[row][col];
}

// Overloaded + operator for matrix addition
MatrixNM MatrixNM::operator+(const MatrixNM& other) const {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::logic_error("MatrixNM: Cannot add matrices of different dimensions");
    }
    MatrixNM result(rows_, cols_);
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            result(i, j) = (*this)(i, j) + other(i, j);
        }
    }
    return result;
}

// Overloaded * operator for scalar multiplication
MatrixNM MatrixNM::operator*(double scalar) const {
    MatrixNM result(rows_, cols_);
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < cols_; ++j) {
            result(i, j) = (*this)(i, j) * scalar;
        }
    }
    return result;
}

// Overloaded * operator for matrix multiplication
MatrixNM MatrixNM::operator*(const MatrixNM& other) const {
    if (cols_ != other.rows_) {
        throw std::logic_error("MatrixNM: Cannot multiply matrices with incompatible dimensions");
    }
    MatrixNM result(rows_, other.cols_);
    for (size_t i = 0; i < rows_; ++i) {
        for (size_t j = 0; j < other.cols_; ++j) {
            for (size_t k = 0; k < cols_; ++k) {
                result(i, j) += (*this)(i, k) * other(k, j);
            }
        }
    }
    return result;
}

// Function to calculate the determinant (only for square matrices)
// This is a recursive implementation for general N x N matrices.
double MatrixNM::determinant() const {
    if (rows_ != cols_) {
        throw std::logic_error("MatrixNM: Determinant can only be calculated for square matrices");
    }
    if (rows_ == 0) {
        return 0.0; // Determinant of an empty matrix is 0
    }
    if (rows_ == 1) {
        return (*this)(0, 0);
    }
    if (rows_ == 2) {
        return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
    }

    double det = 0.0;
    for (size_t c = 0; c < cols_; ++c) {
        // Create a submatrix
        MatrixNM submatrix(rows_ - 1, cols_ - 1);
        for (size_t i = 1; i < rows_; ++i) {
            size_t sub_j = 0;
            for (size_t j = 0; j < cols_; ++j) {
                if (j == c) continue;
                submatrix(i - 1, sub_j) = (*this)(i, j);
                sub_j++;
            }
        }
        // Add/subtract the cofactor
        if (c % 2 == 0) {
            det += (*this)(0, c) * submatrix.determinant();
        } else {
            det -= (*this)(0, c) * submatrix.determinant();
        }
    }
    return det;
}

// Friend function for stream output
std::ostream& operator<<(std::ostream& os, const MatrixNM& m) {
    if (m.rows_ == 0 || m.cols_ == 0) {
        os << "Empty Matrix" << std::endl;
        return os;
    }
    for (size_t i = 0; i < m.rows_; ++i) {
        for (size_t j = 0; j < m.cols_; ++j) {
            os << std::setw(10) << std::fixed << std::setprecision(4) << m(i, j);
        }
        os << std::endl;
    }
    return os;
}

// Friend function for stream input
std::istream& operator>>(std::istream& is, MatrixNM& m) {
    if (m.rows_ == 0 || m.cols_ == 0) {
        std::cout << "Matrix dimensions are 0x0. Cannot read values." << std::endl;
        return is;
    }
    std::cout << "Enter " << m.rows_ * m.cols_ << " values for the " << m.rows_ << "x" << m.cols_ << " matrix:" << std::endl;
    for (size_t i = 0; i < m.rows_; ++i) {
        for (size_t j = 0; j < m.cols_; ++j) {
            is >> m(i, j);
        }
    }
    return is;
}
