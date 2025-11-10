
# HW3 Study Guide: C++ Topics

This guide summarizes the key concepts from lectures 3 through 8 to help you prepare for Homework 3.

## Lecture 3: Multidimensional Arrays & Recursion

### Multidimensional Arrays
- **Declaration**: `type arrayName[rows][columns];`
- **Initialization**: 
  ```cpp
  int matrix[3][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}
  };
  ```
- **Accessing Elements**: `matrix[row][column]`

### Recursion
- A function that calls itself.
- **Base Case**: The condition that stops recursion.
- **Recursive Case**: The part of the function that calls itself.

**Example: Factorial**
```cpp
int factorial(int n) {
    if (n == 0) { // Base case
        return 1;
    } else { // Recursive case
        return n * factorial(n - 1);
    }
}
```

### Function Call Stack
- A LIFO (Last In, First Out) data structure that manages function calls.
- Each function call creates a **stack frame** with local variables and a return address.
- **Stack Overflow**: Occurs if the recursion is too deep and the call stack runs out of memory.

---

## Lecture 4: Pointers & Dynamic Memory

### Pointers
- A variable that stores the memory address of another variable.
- **Declaration**: `int* ptr;`
- **Initialization**: `int* ptr = &var;`
- **Dereferencing**: `*ptr` (accesses the value at the address)
- **Null Pointer**: `int* ptr = nullptr;` (points to nothing)

### Dynamic Memory
- Memory allocated at runtime from the **heap**.
- **`new`**: Allocates memory.
- **`delete`**: Deallocates memory.
- **`new[]`**: Allocates an array.
- **`delete[]`**: Deallocates an array.

**Example:**
```cpp
int* p = new int; // Allocate memory for an integer
*p = 10;
delete p; // Deallocate memory
p = nullptr; // Avoid dangling pointer

int* arr = new int[5]; // Allocate an array
delete[] arr; // Deallocate the array
arr = nullptr;
```
- **Memory Leak**: Forgetting to `delete` allocated memory.
- **Dangling Pointer**: A pointer that points to deallocated memory.

---

## Lecture 5: Classes & Structs

### Classes
- A blueprint for creating objects.
- **Access Specifiers**:
  - `public`: Accessible from anywhere.
  - `private`: Accessible only from within the class.
  - `protected`: Accessible from within the class and derived classes.
- **Constructor**: A special method for creating and initializing an object.
- **Destructor**: A special method that is called when an object is destroyed. Used for cleanup.

**Example:**
```cpp
class Car {
public:
    string brand;
    int year;

    // Constructor
    Car(string b, int y) {
        brand = b;
        year = y;
    }

    // Destructor
    ~Car() {
        cout << "Car destroyed." << endl;
    }
};
```

### Structs
- Similar to classes, but members are `public` by default.
- Typically used for simple data structures without complex behavior.

### Operators
- **Dot Operator (`.`)**: Accesses members of an object. `car1.brand`
- **Arrow Operator (`->`)**: Accesses members of an object through a pointer. `car_ptr->brand`

---

## Lecture 6: Intermediate C++

### Initialization Lists
- A more efficient way to initialize class members in a constructor.
- Required for `const` and reference members.
```cpp
class MyClass {
public:
    MyClass(int a, int b) : member1(a), member2(b) {
        // Constructor body
    }
private:
    int member1;
    int member2;
};
```

### `const` Keyword
- Makes a variable's value unchangeable.
- **`const` member functions**: Promise not to modify the object's data members.
- **`const` parameters**: Prevent a function from modifying the passed arguments.

### Pass by Value vs. Pass by Reference
- **Pass by Value**: A copy of the argument is passed to the function. Changes inside the function do not affect the original variable.
- **Pass by Reference**: A reference to the original argument is passed. Changes inside the function **do** affect the original variable. Use the `&` symbol.
  ```cpp
  void modifyValue(int& value) {
      value = 100; // This will change the original variable
  }
  ```

---

## Lecture 7: Operator Overloading

- Allows you to define the behavior of operators (e.g., `+`, `==`, `<<`) for your custom classes.

**Example: Overloading `+`**
```cpp
class Complex {
public:
    double real, imag;
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload the + operator
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
};
```

### Friend Functions
- A function that is not a member of a class but has access to its `private` and `protected` members.
- Often used to overload operators like `<<` for stream output.
```cpp
class MyClass {
    friend ostream& operator<<(ostream& os, const MyClass& obj);
};
```

---

## Lecture 8: Queues & The Big Five

### `this` Keyword
- A pointer that holds the memory address of the current object.
- Used to differentiate between member variables and parameters with the same name. `this->member = member;`

### Queues
- A First-In, First-Out (FIFO) data structure.
- `std::queue` in the `<queue>` header.
- **`push()`**: Adds an element to the back.
- **`pop()`**: Removes the element from the front.
- **`front()`**: Accesses the front element.
- **`back()`**: Accesses the back element.

### The Big Five (Rule of Five)
If a class manages a resource (like dynamic memory), you should define these five special member functions to handle copying and moving correctly:
1.  **Copy Constructor**: Creates an object from another object (deep copy).
2.  **Copy Assignment Operator**: Assigns one object to another.
3.  **Move Constructor**: Transfers resources from one object to another.
4.  **Move Assignment Operator**: Transfers resources during assignment.
5.  **Destructor**: Releases resources.

- **Shallow Copy**: Copies member values directly. Pointers will point to the same memory.
- **Deep Copy**: Creates new copies of dynamically allocated resources.

### Separation of Interface and Implementation
- **Interface (.h file)**: Class declarations and function prototypes.
- **Implementation (.cpp file)**: Definitions of the functions declared in the header file.
- Helps with code organization and reduces compile times.
- Compile multi-file projects with `g++ main.cpp functions.cpp -o output`.
