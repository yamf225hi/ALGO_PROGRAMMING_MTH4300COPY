#include <string>

#ifndef BOOK_FIXED_H
#define BOOK_FIXED_H

class Book
{
private:
    std::string title;
    std::string author;
    int yearPublished;
    double price;

public:
    // Constructor with default values for optional parameters
    Book(const std::string& bookTitle, const std::string& bookAuthor, int publishedYear = 1900, double bookPrice = 0.0);

    // Member function to apply a discount to the book's price
    void applyDiscount(double discountPERCENTAGE);
    
    // Member function to get book information as a formatted string
    std::string getbookINFO() const; 
};

#endif // BOOK_FIXED_H
