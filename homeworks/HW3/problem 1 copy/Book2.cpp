#include <Book2.h>
#include <iostream>



Book:: Book(const std::string& bookTitle, const std::string bookAuthor, int publishedYear = 1900, double bookPrice = 0) :title(t), author(a), yearPublished(p),price(P);

void Book::applyDiscount(double& discountPERCENTAGE);
{
    price * (discountPERCENTAGE / 100.0);
}


std::string const Book::getbookINFO();
{
    std::cout << "BOOK TITLE:" << title << , << "BOOK AUTHOR: "<< author<< , <<"YEAR PUBLISHED: " << yearPublished << "PRICE BEFORE DISCOUNT" << price<< std::endl;
}



