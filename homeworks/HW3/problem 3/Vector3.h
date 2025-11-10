#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>

class Vector3 {
private:
    double x_, y_, z_;

public:
    // Constructors
    Vector3(double x = 0, double y = 0, double z = 0);

    // Overload () operator to access elements
    double& operator()(int index);
    const double& operator()(int index) const;

    // Friend functions for operator overloading
    friend std::ostream& operator<<(std::ostream& out, const Vector3& v);
    friend std::istream& operator>>(std::istream& in, Vector3& v);
};

#endif // VECTOR3_H
