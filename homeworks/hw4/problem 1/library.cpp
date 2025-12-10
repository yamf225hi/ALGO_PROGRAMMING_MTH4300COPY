#include "library.h"
#include <iostream>
#include "problem 1 copy/Book2.h"

// 1. Default constructor
Library::Library() : books(nullptr), size(0) {}

// 2. Parameterized constructor

Library::Library(size_t n): size(n) {
    books = new Book[size];
}

// 3. Copy constructor
Library::Library(const Library& other) : size(other.size) {
    books = new Book[size];
    for (size_t i = 0; i < size; ++i) {
        books[i] = other.books[i];
    }
}

// 4. Copy assignment operator
Library& Library::operator=(const Library& other) {
    if (this != &other) {
        delete[] books;
        size = other.size;
        books = new Book[size];
        for (size_t i = 0; i < size; ++i) {
            books[i] = other.books[i];
        }
    }
    return *this;
}

// 5. Move constructor
Library::Library(Library&& other) : books(other.books), size(other.size) {
    other.books = nullptr;
    other.size = 0;
}

// 6. Move assignment operator
Library& Library::operator=(Library&& other) {
    if (this != &other)
    {
        delete[] books;
        books = other.books;
        size = other.size;
        other.books = nullptr;
        other.size = 0;
    }
    return *this;
}

// 7. Destructor
Library::~Library()
{
    delete[] books;
}

// Utility functions
void Library::setBook(size_t index, const Book& book)
{
    if (index < size)
    {
        books[index] = book;
    }
}

void Library::print() const 
{
    for (size_t i = 0; i < size; ++i) 
    {
        std::cout << "Book " << i + 1 << ": " << books[i].getbookINFO() << std::endl;
    }
}

size_t Library::getSize() const 
{
    return size;
}