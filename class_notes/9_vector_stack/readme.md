# Lecture notes

## table of contents
1. Vectors
2. Stacks
3. Practice Examples



## Vector Class
A ```C++``` ```vector``` is a dynamic array that can grow or shrink in size. Let's break down how a ```vector``` works as a class and what its key components are.


#### Key Components of the Vector Template
* Data Member (```T* data```):
  * The vector stores a pointer to a dynamically allocated array where the elements are stored. The type ```T``` is determined when an object of ```MyVector``` is instantiated (for example, ```MyVector<int>``` would use an array of integers).

* Size and Capacity:
  * The ```size``` keeps track of the number of elements that have been added to the vector, while ```capacity``` represents the amount of allocated memory. If more elements are added than the current capacity, the array is resized (usually doubled).

* Constructor and Destructor:
  * The constructor initializes the vector with a default capacity of 1. The destructor releases the memory when the object goes out of scope to prevent memory leaks.

* push_back():
  * This function adds an element to the vector. If the vector is full (i.e., ```size == capacity```), it calls ```resize()``` to allocate a larger array and copy the existing elements to the new array.

* operator[]:
  * Overloading the ```[]``` operator allows access to elements by their index, just like an array. It also checks for out-of-bounds access.

* resize():
  * This is a helper function that reallocates memory for the vector when the current capacity is reached, ensuring that the vector can continue to grow dynamically.


### Real-world Vector Example in STL
The ```std::vector``` class in the STL works similarly, but with many more features and optimizations (e.g., iterators, range-based access, etc.). Here's how you'd use ```std::vector```:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << "Vector elements: ";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }

    return 0;
}
```

In this case, the ```std::vector<int>``` stores integers, dynamically grows, and manages its memory efficiently without the need for manual memory management.

### Why Use a Template for Vectors?
Using templates allows you to write generic code that works with any data type. This avoids code duplication and makes the ```vector``` class versatile, enabling you to store objects of any type:

```std::vector<int>``` for integers
```std::vector<std::string>``` for strings
```std::vector<MyClass>``` for user-defined types like ```MyClass```

### Conclusion
The ```vector``` template class in C++ is a powerful and flexible way to handle dynamic arrays. By using templates, the ```vector``` class can store elements of any type, and with functions like ```push_back()``` and dynamic resizing, it efficiently manages memory and grows as needed. The STL ```std::vector``` is a well-optimized implementation of this idea.


## Stacks
A **stack** is a linear data structure that follows the **LIFO** (Last In, First Out) principle, meaning the last element added to the stack is the first one to be removed. It can be visualized as a collection of items stacked on top of each other, where only the topmost item can be accessed or removed.

### Key Operations of a Stack:
* **Push:** Adds an element to the top of the stack.
* **Pop:** Removes the element from the top of the stack.
* **Peek (or Top):** Retrieves the top element without removing it.
* **isEmpty:** Checks if the stack is empty.


### Advantages of a Stack:
* Simplicity: Ideal for solving problems like reversing a string or validating parentheses.
* Efficient: Push and pop operations are O(1).
* Useful in algorithms like depth-first search, function call stacks, etc.

### Applications of a Stack:
* **Expression Evaluation:** Parsing and evaluating expressions (e.g., postfix evaluation).
* **Undo Mechanism:** Used in text editors for undo operations.
* **Recursion:** Call stack in programming.
* **Depth-First Search (DFS):** Used in graph and tree traversal algorithms.


## Practice Examples
1. Given a queue of strings and an integer k, reverse the order of the first k elements of the queue, leaving the rest of the elements in the same order. You must use:

* A stack to help reverse the first k elements.
* A queue to represent the original data.
* A vector to return or display the final result.

2. Notice that our three classes share a lot of code for managing dynamic arrays. To eliminate this redundancy, create a new class called ResourceArray that encapsulates all the common logic, including the Big Five (constructor, destructor, copy/move constructors, and copy/move assignment operators).

Then, instead of directly managing arrays with new in each of your classes, use ResourceArray as a member to handle the array storage. This way, Queue, Stack, Vector and any other class can reuse the same array management code safely and efficiently.