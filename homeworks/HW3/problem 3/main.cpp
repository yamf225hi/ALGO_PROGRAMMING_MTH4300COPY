#include <iostream>
#include "Matrix33.h"
#include "Vector3.h"

// Function to compute Ax = b
Vector3 multiply(const Matrix33& A, const Vector3& x) {
    Vector3 b;
    for (int i = 0; i < 3; ++i) {
        b(i) = A(i, 0) * x(0) + A(i, 1) * x(1) + A(i, 2) * x(2);
    }
    return b;
}

int main() {
    Matrix33 A;
    Vector3 x;

    // Prompt user for matrix and vector
    std::cin >> A;
    std::cin >> x;

    // Compute the product
    Vector3 b = multiply(A, x);

    // Print the result
    std::cout << "The resulting vector b is: " << b << std::endl;

    return 0;
}
