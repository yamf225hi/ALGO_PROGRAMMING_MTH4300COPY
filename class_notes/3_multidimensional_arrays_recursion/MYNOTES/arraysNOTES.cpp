#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Array size: " << size; // Outputs 5
    return 0;
}

//multidimensional arrays:
/*it kinda looks like a matrix. the first number are the rows, the second number are the columns. */
int matrix[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
    };
    //accessing elements or rather printing out the stuff:
    cout << matrix[0][0]; // Outputs 1
    cout << matrix[1][2]; // Outputs 6 

    return 0;
}
