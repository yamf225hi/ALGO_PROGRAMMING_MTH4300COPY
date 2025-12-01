#include "Book.h"
#include <iostream>
#include <string>

Book::Book(const std::string& bookTitle, const std::string& bookAuthor, int publishedYear, double bookPrice)
    : title(bookTitle), author(bookAuthor), yearPublished(publishedYear), price(bookPrice) {
}

void Book::applyDiscount(double& discount) {
    price -= price * (discount / 100.0);
}

std::string Book::getBookInfo() const {
    return "Title: " + title + "\nAuthor: " + author + "\nYear Published: " + std::to_string(yearPublished) + "\nPrice: $" + std::to_string(price);
}


