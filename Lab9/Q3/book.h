#ifndef BOOK_H
#define BOOK_H
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;
public:
    Book(std::string t, std::string a, std::string i);
    std::string getTitle();
    std::string getAuthor();
    std::string getISBN();
};

#endif