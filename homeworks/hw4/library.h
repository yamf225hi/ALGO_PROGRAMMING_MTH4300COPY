#include <string>
#include "Book2.h"
#ifndef LIBRARY_H
#define LIBRARY_H

class Library {
private: 
    Book* books; //dynamically allocated array of book objects
    size_t size;

public: 
    Library(); // 1. Default constructor
    Library(size_t, n); // 2. Parameterized constructor
    Library(const Library& other); // 3. Copy constructor
    Library& operator=(const Library& other); // 4. Copy assignment operator
    Library(Library&& other); // 5. Move constructor
    Library& operator=(Library&& other); // 6. Move assignment operator

    ~Library(); // 7. Destructor

// Utility functions
void setBook(size_t index, const Book& book); 
void print() const; size_t getSize() const;

};

#endif