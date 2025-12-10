#include <iostream>
#include "library.h"
#include "problem 1 copy/Book2.h"

int main() {
    // Create a library of 3 books
    Library library1(3);

    // Create 3 book objects
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 1922, 388.99);
    Book book2("To Kill a Mockingbird", "Harper Lee", 1960, 12.99);
    Book book3("1984", "George Orwell", 1949, 10.99);

    // Set the books in the library
    library1.setBook(0, book1);
    library1.setBook(1, book2);
    library1.setBook(2, book3);

    // Print the library
    std::cout << "--- Library 1 ---" << std::endl;
    library1.print();
    std::cout << std::endl;

    // Test the copy constructor
    std::cout << "--- Testing Copy Constructor ---" << std::endl;
    Library library2 = library1;
    std::cout << "Library 2 (copy of Library 1):" << std::endl;
    library2.print();
    std::cout << std::endl;

    // Test the copy assignment operator
    std::cout << "--- Testing Copy Assignment Operator ---" << std::endl;
    Library library3;
    library3 = library1;
    std::cout << "Library 3 (assigned from Library 1):" << std::endl;
    library3.print();
    std::cout << std::endl;

    // Test the move constructor
    std::cout << "--- Testing Move Constructor ---" << std::endl;
    Library library4 = std::move(library1);
    std::cout << "Library 4 (moved from Library 1):" << std.endl;
    library4.print();
    std::cout << "Library 1 after move:" << std::endl;
    library1.print();
    std::cout << std::endl;
    
    // library1 is now empty, so let's give it some books back to test move assignment
    library1 = Library(2);
    Book book4("The Catcher in the Rye", "J.D. Salinger", 1951, 8.99);
    Book book5("Pride and Prejudice", "Jane Austen", 1813, 7.99);
    library1.setBook(0, book4);
    library1.setBook(1, book5);


    // Test the move assignment operator
    std::cout << "--- Testing Move Assignment Operator ---" << std::endl;
    Library library5;
    library5 = std::move(library1);
    std::cout << "Library 5 (move assigned from Library 1):" << std::endl;
    library5.print();
    std::cout << "Library 1 after move assignment:" << std::endl;
    library1.print();
    std::cout << std::endl;


    return 0;
}