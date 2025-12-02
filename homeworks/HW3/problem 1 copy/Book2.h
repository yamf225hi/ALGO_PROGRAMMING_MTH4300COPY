#include <string>
#ifndef Book2_h
#define Book2_h


class Book
{
private:
    std::string title;
    std::string author;
    int yearPublished;
    double price;

public:
    Book(const std::string& bookTitle, const std::string& bookAuthor, int publishedYear=1900, double bookPrice =0.0 ); // -> constructor declaration with defualt values. 

    // the member function declaration: 
    void applyDiscount(double discountPERCENTAGE);
    
    std::string const getbookINFO(); 


};

#endif
//so this is the nd of hte header file. 