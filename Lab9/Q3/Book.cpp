#include "Book.h"

Book::Book(std::string t, std::string a, std::string i) 
    : title(t), author(a), ISBN(i) {}

std::string Book::getTitle() { return title; }
std::string Book::getAuthor() { return author; }
std::string Book::getISBN() { return ISBN; }