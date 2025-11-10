#include "MatrixNM.h"
#include <iostream>

int main() {
    // Test default constructor
    MatrixNM m_empty;
    std::cout << "Empty Matrix (default constructor):" << std::endl;
    std::cout << m_empty << std::endl;

    // Test constructor with dimensions
    MatrixNM m1(2, 3);
    std::cout << "Matrix m1 (2x3, initialized to 0):" << std::endl;
    std::cout << m1 << std::endl;

    // Test input operator
    MatrixNM m2(2, 2);
    std::cin >> m2;
    std::cout << "Matrix m2 (from input):" << std::endl;
    std::cout << m2 << std::endl;

    // Test addition
    MatrixNM m3(2, 2);
    m3(0,0) = 1; m3(0,1) = 2;
    m3(1,0) = 3; m3(1,1) = 4;
    std::cout << "Matrix m3:" << std::endl;
    std::cout << m3 << std::endl;

    try {
        MatrixNM m_sum = m2 + m3;
        std::cout << "Matrix m2 + m3:" << std::endl;
        std::cout << m_sum << std::endl;
    } catch (const std::logic_error& e) {
        std::cerr << "Error adding matrices: " << e.what() << std::endl;
    }

    // Test scalar multiplication
    MatrixNM m_scalar = m3 * 2.0;
    std::cout << "Matrix m3 * 2.0:" << std::endl;
    std::cout << m_scalar << std::endl;

    // Test matrix multiplication
    MatrixNM m4(2, 3);
    m4(0,0) = 1; m4(0,1) = 2; m4(0,2) = 3;
    m4(1,0) = 4; m4(1,1) = 5; m4(1,2) = 6;
    std::cout << "Matrix m4 (2x3):" << std::endl;
    std::cout << m4 << std::endl;

    MatrixNM m5(3, 2);
    m5(0,0) = 7; m5(0,1) = 8;
    m5(1,0) = 9; m5(1,1) = 1;
    m5(2,0) = 2; m5(2,1) = 3;
    std::cout << "Matrix m5 (3x2):" << std::endl;
    std::cout << m5 << std::endl;

    try {
        MatrixNM m_product = m4 * m5; // Result should be 2x2
        std::cout << "Matrix m4 * m5 (2x2):" << std::endl;
        std::cout << m_product << std::endl;
    } catch (const std::logic_error& e) {
        std::cerr << "Error multiplying matrices: " << e.what() << std::endl;
    }

    // Test determinant
    MatrixNM m_det(3, 3);
    m_det(0,0) = 1; m_det(0,1) = 2; m_det(0,2) = 3;
    m_det(1,0) = 0; m_det(1,1) = 1; m_det(1,2) = 4;
    m_det(2,0) = 5; m_det(2,1) = 6; m_det(2,2) = 0;
    std::cout << "Matrix m_det (3x3):" << std::endl;
    std::cout << m_det << std::endl;

    try {
        std::cout << "Determinant of m_det: " << m_det.determinant() << std::endl;
    } catch (const std::logic_error& e) {
        std::cerr << "Error calculating determinant: " << e.what() << std::endl;
    }

    MatrixNM m_non_square(2, 3);
    std::cout << "Matrix m_non_square (2x3):" << std::endl;
    std::cout << m_non_square << std::endl;
    try {
        std::cout << "Determinant of m_non_square: " << m_non_square.determinant() << std::endl;
    } catch (const std::logic_error& e) {
        std::cerr << "Error calculating determinant: " << e.what() << std::endl;
    }

    return 0;
}
