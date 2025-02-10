// TASK # 02
// Scenario:
// A library system allows users to borrow and return books. The system should:
// 1. Add new books to the collection.
// 2. Borrow books (check availability).
// 3. Return books.
// 4. Display all available books.
// Requirements:
//  Implement a Book class with attributes: ID, title, author, availability.
//  Implement a Library class with:
// 1. Method to add a book (with unique ID).
// 2. Method to borrow a book (updates availability).
// 3. Method to return a book (marks it available).
// 4. Method to display all available books.
//  Store book records dynamically using pointers and DMA.
//  Use constructor overloading to initialize books with or without availability status.


#include <iostream>

using namespace std;

class Book
{
        int id;
        string title;
        string author;
        bool availability;

    public:

        void setId(int id)
        {
            this-> id = id;
        }

        void setTitle(string title)
        {
            this-> title = title;
        }

         void setAuthor(string author)
        {
            this-> author = author;
        }

         void setAvailability(bool availability)
        {
            this-> availability = availability;
        }

        int getid()
        {
            return id;
        }
        string gettitle()
        {
            return title;
        }
        string getauthor()
        {
            return author;
        }
        bool getavailability()
        {
            return availability;
        }


};

class Library
{
private:
    Book *b;
    int c;

public:
    Library()
    {
        b = new Book[10];
        c = 0;
    }
    Library(int size)
    {
        b = new Book[size];
        c = 0;
    }

    void addBook()
    {   int ID;
        string Title, Author;
        bool available;
        cout <<"Enter book details here: "<<endl;
        cout <<"Enter ID: ";
        cin >> ID;
        b[c].setId(ID);
        cout<<"Enter Title: ";
        cin>>Title;
        b[c].setTitle(Title);
        cout<<"Enter Author: ";
        cin>>Author;
        b[c].setAuthor(Author);
        b[c].setAvailability(true);
        c++;

    }

    void Borrowbook(string Bname)
    {
        for(int i = 0; i < c; i++)
        {
            if(b[i].gettitle() == Bname)
            {
                if(b[i].getavailability() == true)
                {
                    cout << "the required book is borrowed" << endl;
                    b[i].setAvailability(false);
                    return;
                }
                else
                {
                    cout << "the following book is un available" << endl; 
                }
            }
        }

        cout << "the book name you have provided is wrong" << endl;
    }

    void ReturnBook(string Bname)
    {
        for(int i = 0; i < c; i++)
        {
            if(b[i].gettitle() == Bname)
            {
                cout << "your book is returned" << endl;
                b[i].setAvailability(true);
                return;
            }
        }
        cout << "the book name you have provided is wrong" << endl;
    }

    void displayBook()
    {
        for(int i = 0; i < c; i++)
        {
            if(b[i].getavailability() == true)
            {
                cout << "Book Id: " << b[i].getid() << endl;
                cout << "Title: " << b[i].gettitle() << endl;
                cout << "Author name: " << b[i].getauthor() << endl;
                
            }
        }
    }


    ~Library()
    {
        delete [] b;
    }



};

int main()
{

    Library L;
    L.addBook();
    L.addBook();
    string borrow;
    string r;
    cout << "Enter book to be borrowed: ";
    cin >> borrow;
    L.Borrowbook(borrow);
    cout << " Enter book to be returned: ";
    cin >> r;
    L.ReturnBook(r);
    L.displayBook();

}