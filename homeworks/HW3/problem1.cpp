#include <iostream>
#include <string>

// =====================================================================================
// This section is what would typically be in the "Book.h" file.
// It contains the declaration of the Book class, which tells the compiler what a Book
// object is, what data it holds (private members), and what it can do (public methods).
// =====================================================================================
class Book {
private:
    // These are the private data members of the class.
    // They can only be accessed by the methods of the class itself.
    std::string title;
    std::string author;
    int yearPublished;
    double price;

public:
    // This is the constructor. It's a special method that gets called when a new Book
    // object is created. It's used to initialize the data members.
    Book(const std::string& bookTitle, const std::string& bookAuthor, int publishedYear = 1900, double bookPrice = 0.0);

    // This is a method that applies a discount to the book's price.
    void applyDiscount(double& discount);

    // This is a method that returns a string with the book's information.
    // The "const" at the end means that this method doesn't change any of the
    // data members of the class.
    std::string getBookInfo() const;
};

// =====================================================================================
// This section is what would typically be in the "Book.cpp" file.
// It contains the implementation of the methods declared in the Book class.
// =====================================================================================

// This is the implementation of the constructor.
// It uses an initialization list to set the values of the data members.
Book::Book(const std::string& bookTitle, const std::string& bookAuthor, int publishedYear, double bookPrice)
    : title(bookTitle), author(bookAuthor), yearPublished(publishedYear), price(bookPrice) {
    // The body of the constructor is empty because the initialization list
    // does all the work.
}

// This is the implementation of the applyDiscount method.
void Book::applyDiscount(double& discount) {
    // The price is reduced by the discount percentage.
    price -= price * (discount / 100.0);
}

// This is the implementation of the getBookInfo method.
std::string Book::getBookInfo() const {
    // It returns a formatted string with the book's details.
    return "Title: " + title + "\nAuthor: " + author + "\nYear Published: " + std::to_string(yearPublished) + "\nPrice: $" + std::to_string(price);
}

// =====================================================================================
// This section is what would typically be in the "main.cpp" file.
// It contains the main function, which is the entry point of the program.
// =====================================================================================
int main() {
    // Here we create a Book object.
    std::string bookName = "The Great Gatsby";
    std::string author = "F. Scott Fitzgerald";
    Book myBook(bookName, author, 1925, 15.99);

    // We print the initial information of the book.
    std::cout << "--- Initial Book Info ---" << std::endl;
    std::cout << myBook.getBookInfo() << std::endl;

    // We apply a 10% discount to the book.
    double discount = 10.0;
    myBook.applyDiscount(discount);

    // We print the information of the book after the discount.
    std::cout << "\n--- Book Info After Discount ---" << std::endl;
    std::cout << myBook.getBookInfo() << std::endl;

    return 0;
}
