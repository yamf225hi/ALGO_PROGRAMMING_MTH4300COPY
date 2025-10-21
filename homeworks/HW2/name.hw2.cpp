
// 1. Implement a Dynamic 2D Array (Matrix) Using Pointer


#include <iostream>
using namespace std;

int main() {
    int m, n;
    cout << "Enter two integers: ";
    cin >> m >> n;

    // Input validation should come FIRST
    if (m <= 0 || n <= 0) {
        cout << "Invalid input. Please enter positive integers for rows and columns." << endl;
        return 1; // Exit the program with an error code
    }

    // Dynamically allocate memory for the 2D array
    int **arr = new int *[m];
    for (int i = 0; i < m; i++) {
        arr[i] = new int[n];
    }

    // Initialize the 2D array with consecutive numbers
    int value = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = value++;
        }
    }

    // Print the matrix to the console
    cout << "The " << m << "x" << n << " matrix is:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory properly
    for (int i = 0; i < m; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
