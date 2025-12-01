# Lecture notes

## table of contents
1. Exception Handling
2. Testing and Unit Testing
3. Numeric Limits
4. Random with random_device
5. Templates
6. Command Line Arguments



## Exception Handling
Exception handling lets you respond to errors without crashing your program.

### Key keywords:
- try → code that might fail  
- throw → signal an error  
- catch → handle the error  

#### Example:
```cpp
try {
    if (b == 0)
        throw std::runtime_error("Division by zero");
    int result = a / b;
}
catch (const std::runtime_error& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```

#### Why it matters:
- Provides safe error handling  
- Separates normal logic from error-handling logic  
- Prevents crashing  

---

## Testing and Unit Testing
Testing ensures code works correctly.

### Types:
- Testing → general verification  
- Unit testing → test individual functions/classes  

#### Why:
- Catch bugs early  
- Prevent regressions  
- Verify edge cases  

### Example (simple manual unit test):
```cpp
int add(int a, int b) { return a + b; }

void test_add() {
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
}

int main() {
    test_add();
}
```

Common C++ testing frameworks:
- GoogleTest  
- Catch2  
- Doctest  

---

## Numeric Limits
`std::numeric_limits<T>` gives information about numeric type ranges.

### Example:
```cpp
std::cout << std::numeric_limits<int>::max() << "\n";
std::cout << std::numeric_limits<float>::lowest() << "\n";
std::cout << std::numeric_limits<double>::epsilon() << "\n";
```

### Useful for:
- Avoiding overflow  
- Writing portable code  
- Understanding precision  

---

## Random with random_device
`std::random_device` provides better randomness than `rand()`.

### Example:
```cpp
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dist(1, 100);

int x = dist(gen);
```

### Advantages:
- Better randomness  
- Thread-safe  
- Works with standard distributions  

---

## Templates
Templates allow type-independent (generic) code.

### Function template:
```cpp
template<typename T>
T multiply(T a, T b) {
    return a * b;
}
```

### Class template:
```cpp
template<typename T>
class Box {
public:
    T value;
    Box(T v) : value(v) {}
};
```

### Benefits:
- Reusable code  
- Type safety  
- Used heavily in STL  

---

## Command Line Arguments
In C++, command-line arguments come through `main`.

```cpp
int main(int argc, char* argv[])
```

### Example:
Command:
```
./program hello 123
```

Program:
```cpp
int main(int argc, char* argv[]) {
    std::cout << "Args: " << argc << "\n";
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << "\n";
}
```

---

