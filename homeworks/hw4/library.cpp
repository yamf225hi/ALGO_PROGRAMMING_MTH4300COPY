#include "library.h"
#include "Book2.cpp"

#include "Book2.h"
#include <string>


//constructor defintin: 
Book::Book(const std::string& bookTitle, const std::string& bookAuthor, int publishedYear, double bookPrice) 
    :title(bookTitle), author(bookAuthor), yearPublished(publishedYear),price(bookPrice)
    {
            //construcor body. empty since all work done in the initializer list. 
    }

void Book::applyDiscount(double discountPERCENTAGE)
    {
        price -= price * (discountPERCENTAGE / 100.0);
    }


std::string Book::getbookINFO() const
{
    std::string bookinfo = 
        "Title" + title + "Author" + author + "Year Published" + std::to_string(yearPublished) + "price" + std::to_string(price);

    return bookinfo;

}