#include <iostream>
#include "Book_fixed.h" // Changed to include the fixed header

int main()
{ 
    // --- Create a Book object using all constructor arguments ---
    Book book1("The Great Gatsvy", "F. Scoot FItzergferlad", 1922, 388.99); 

    // print intitial detials of book1: 
    std::cout << "INITIAL BOOK 1 INFO: " << book1.getbookINFO() << std::endl;

    // DISCUONTS:
    double discount_value = 2.0;
    book1.applyDiscount(discount_value);

    // print details after discount
    std::cout << "BOOK 1 INFO AFTER " << discount_value << "% DISCOUNT: " << book1.getbookINFO() << std::endl;

    return 0;

}
