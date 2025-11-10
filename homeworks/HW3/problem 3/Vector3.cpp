#include "Vector3.h"
#include <iostream>
#include <stdexcept>

// Constructor
Vector3::Vector3(double x, double y, double z) : x_(x), y_(y), z_(z) {}

// Overload () operator to access elements
double& Vector3::operator()(int index) {
    switch (index) {
        case 0: return x_;
        case 1: return y_;
        case 2: return z_;
        default: throw std::out_of_range("Vector3 index out of range");
    }
}

const double& Vector3::operator()(int index) const {
    switch (index) {
        case 0: return x_;
        case 1: return y_;
        case 2: return z_;
        default: throw std::out_of_range("Vector3 index out of range");
    }
}

// Overload << operator to print the vector
std::ostream& operator<<(std::ostream& out, const Vector3& v) {
    out << "(" << v.x_ << ", " << v.y_ << ", " << v.z_ << ")";
    return out;
}

// Overload >> operator to read vector values from user
std::istream& operator>>(std::istream& in, Vector3& v) {
    std::cout << "Enter 3 values for the vector (x y z): ";
    in >> v.x_ >> v.y_ >> v.z_;
    return in;
}
