#include <iostream>
#include "Book.h"
#include "Library.h"

int main() {

    Book book1("Atomic Habits", "Robert", "978-0321563842");
    Book book2("Clean Code", "Robert Martin", "978-0132350884");
    
    Library library;
    library.addBook(book1);
    library.addBook(book2);
    
    std::cout << "Library Books:\n";
    std::cout << "1. " << book1.getTitle() << " by " << book1.getAuthor() 
              << " (ISBN: " << book1.getISBN() << ")\n";
    std::cout << "2. " << book2.getTitle() << " by " << book2.getAuthor() 
              << " (ISBN: " << book2.getISBN() << ")\n";
    
    Book* found = library.searchBook("Clean Code");
    if (found) {
        std::cout << "\nFound book: " << found->getTitle() << "\n";
    }
    
    return 0;
}
