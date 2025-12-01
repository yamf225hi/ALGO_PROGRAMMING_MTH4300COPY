#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int yearPublished;
    double price;

public:
    Book(const std::string& bookTitle, const std::string& bookAuthor, int publishedYear = 1900, double bookPrice = 0.0);

    void applyDiscount(double& discount);
    std::string getBookInfo() const;
};

#endif // BOOK_H
