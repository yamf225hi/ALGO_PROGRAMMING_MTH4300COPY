#ifndef MATRIX33_H
#define MATRIX33_H

#include <iostream>

class Matrix33 {
private:
    double matrix[3][3];

public:
    // Default constructor
    Matrix33();

    // Constructor that takes a 2D array
    Matrix33(double arr[3][3]);

    // Overload () operator to access elements
    double& operator()(int row, int col);
    const double& operator()(int row, int col) const;

    // Overload << operator to print the matrix
    friend std::ostream& operator<<(std::ostream& os, const Matrix33& m);

    // Overload >> operator to read matrix values from user
    friend std::istream& operator>>(std::istream& is, Matrix33& m);
};

#endif // MATRIX33_H
