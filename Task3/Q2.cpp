/* Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a 50 cent toll. Mostly they do, but
sometimes a car goes by without paying. The tollbooth keeps track of the number of cars that have gone by, and of
the total amount of money collected. Model this tollbooth with a class called tollBooth. The two data items are a type 
unsigned int to hold the total number of cars, and a type double to hold the total amount of money collected. 
A constructor initializes both of these to 0. A member function called payingCar() increments the car total and adds 
0.50 to the cash total. Another function, called nopayCar(), increments the car total but adds nothing to the cash total. 
Finally, a member function called display() displays the two totals. Make appropriate member functions const.
Include a program to test this class. This program should allow the user to push one key to count a paying car, and
another to count a nonpaying car. Pushing the Esc key should cause the program to print out the total cars and
total cash and then exit. */

#include <iostream>
#include <conio.h>
using namespace std;

class tollBooth
{
    unsigned int totalCars;
    double totalAmount;

public:
    tollBooth()
    {
        totalCars = 0;
        totalAmount = 0;
    }

    void payingCar()
    {
        totalCars++;
        totalAmount += 0.50;
    }

    void nopayCar()
    {
        totalCars++;
    }

    void display()
    {
        cout << endl;
        cout << "The total number of cars that have gone by so far are " << totalCars << endl;
        cout << "The total amount of money collected so far is " << totalAmount << " cents" << endl;
    }
};

int main()
{
    tollBooth t1;
    char choice;
    cout << "----- Welcome to the Toll Booth system -----" << endl;
    cout << "Press \'P\' for a paying car and \'N\' for a non-paying car" << endl;
    cout << "Press the Esc key to display the total cars passed and total cash collected" << endl;
    while (1)
    {
        cout << endl << "Enter your choice: ";
        choice = _getch();

        switch (choice)
        {
        case 'P':
        case 'p':
            t1.payingCar();
            break;

        case 'N':
        case 'n':
            t1.nopayCar();
            break;

        case char(27):  // 27 is the ASCII code for the ESC key
            t1.display();
            cout << "Exiting the program..." << endl;
            return 0;
        }
    }
}
