#include <string>
#ifndef rectangle_h
#define rectangle_h


 

class Book {
private:
    std:: string title;
    std:: string author;
    int yearPublished;
    double price;

public:
    Book(const std:: string& bookTitle, const std:: string& bookAuthor, int publishedYear=1900, double bookPrice =0.0 ): 
    title(bookTitle), author(bookAuthor), yearPublished(publishedYear), price(bookPrice)

    {
        
    };


};

#endif
//so this is the nd of hte header file. 