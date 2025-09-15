//function to 
#include <iostream>
using namespace std;

// Function DECLARATION: 
int max(int a, int b);
void function_name(string string_name, string string_name2);

// Function DEFINTION for max
int max(int a, int b) {
    //store result in variable m:
    int m = (a > b) ? a : b;
    return m;
}

int main() {
    // Example usage of the max function
    int a = 5;
    int b = 10;
    int maximum = max(a, b);
    cout << "The maximum value is: " << maximum << endl;

    // Check if x is in (5,15) OR (95,202)
    int x;
    cout << "Enter a real number x: ";
    cin >> x;
    
    // Check if x is in (5,15) OR (95,202)
    if ((x > 5 && x < 15) || (x > 95 && x < 202)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    // Prompt user until they enter an integer > 100
    int x100;
    
    do {
        cout << "Enter an integer (must be > 100): ";
        cin >> x;
        
        if (x <= 100) {
            cout << "Try again with a bigger number." << endl;
        }
    } while (x <= 100);
    
    cout << "Congratulations! You know about big numbers!" << endl;
    
    return 0;
}