// pro of recursion is that the algorithm is simpler and easier to understand
// con of recursion is that it uses more memory and is slower and confusion to track (debug which means tryna find the error in the code). 

// FACTORIAL FUNCTION: 
#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0) {
        // Base case: factorial of 0 is 1
        // base case is where the recursion stops, if we dont have a base case the function will keep calling itself forever and eventually crash the program.
        return 1;
    } else {
        // Recursive case: n * factorial of (n-1)
        return n * factorial(n - 1);
    }
}

int main() {
    int number = 10;
    cout << "Factorial of " << number << " is " << factorial(number) << endl;
    return 0;
}

// EXPLANATION:
// The function factorial calls itself with a decremented value of n until it reaches the base case