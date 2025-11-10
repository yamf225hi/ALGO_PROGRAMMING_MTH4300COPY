#ifndef MATRIX_NM_H
#define MATRIX_NM_H

#include <vector>
#include <iostream>
#include <stdexcept> // For std::out_of_range and std::logic_error

class MatrixNM {
private:
    std::vector<std::vector<double>> matrix;
    size_t rows_;
    size_t cols_;

public:
    // Default constructor (creates a 0x0 matrix)
    MatrixNM();

    // Constructor with dimensions
    MatrixNM(size_t rows, size_t cols);

    // Accessors for dimensions
    size_t getRows() const { return rows_; }
    size_t getCols() const { return cols_; }

    // Overload () operator for element access
    double& operator()(size_t row, size_t col);
    const double& operator()(size_t row, size_t col) const;

    // Overloaded operators (declarations)
    MatrixNM operator+(const MatrixNM& other) const;
    MatrixNM operator*(const MatrixNM& other) const; // Matrix multiplication
    MatrixNM operator*(double scalar) const;         // Scalar multiplication

    // Function to calculate the determinant (only for square matrices)
    double determinant() const;

    // Friend functions for stream operators
    friend std::ostream& operator<<(std::ostream& os, const MatrixNM& m);
    friend std::istream& operator>>(std::istream& is, MatrixNM& m);
};

#endif // MATRIX_NM_H
