#include "Book_fixed.h" // Use the new header file
#include <string>      // For std::to_string

// Constructor definition:
// Default parameter values are specified in the header, not in the implementation.
Book::Book(const std::string& bookTitle, const std::string& bookAuthor, int publishedYear, double bookPrice) 
    : title(bookTitle), author(bookAuthor), yearPublished(publishedYear), price(bookPrice)
{
    // Constructor body is empty as all work is done in the initializer list.
}

void Book::applyDiscount(double discountPERCENTAGE)
{
    // Apply the discount to the current price
    price -= price * (discountPERCENTAGE / 100.0);
}

std::string Book::getbookINFO() const
{
    // Return a formatted string with book details
    std::string bookinfo = 
        "Title: " + title + 
        ", Author: " + author + 
        ", Year Published: " + std::to_string(yearPublished) + 
        ", Price: $" + std::to_string(price);

    return bookinfo;
}
