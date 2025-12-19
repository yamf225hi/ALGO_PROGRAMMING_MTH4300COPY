#include <iostream>
using namespace std;

int main()
{
    // REFERENCES EXAMPLE
    string food = "pizza";
    string &meal = food;
    cout << "the food is" << meal << endl;
   


        // POINTERS EXAMPLE: 
        string* ptr = &food;    // A pointer variable, with the name ptr, that stores the address of food

        // Output the value of food (Pizza)
        cout << food << "\n";

        // Output the memory address of food (0x6dfed4)
        cout << &food << "\n";

        // Output the MEMORY ADDRESS of food with the POINTER (0x6dfed4)
        cout << ptr << "\n";

        // dereference: output the VALUE of food with the pointer
        cout << *ptr << "\n";
        
        // CHECK MEMORY SIZE: 
        cout << sizeof(food);
        return 0;
}

