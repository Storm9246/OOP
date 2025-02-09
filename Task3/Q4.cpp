/* In ocean navigation, locations are measured in degrees and minutes of latitude and longitude. Thus if you’re lying
off the mouth of Papeete Harbor in Tahiti, your location is 149 degrees 34.8 minutes west longitude, and 17
degrees 31.5 minutes south latitude. This is written as 149°34.8’ W, 17°31.5’ S. There are 60 minutes in a degree.
(An older system also divided a minute into 60 seconds, but the modern approach is to use decimal minutes
instead.) Longitude is measured from 0 to 180 degrees, east or west from Greenwich, England, to the international
dateline in the Pacific. Latitude is measured from 0 to 90 degrees, north or south from the equator to the poles.
Create a class angle that includes three member variables: an int for degrees, a float for minutes, and a char for the
direction letter (N, S, E, or W). This class can hold either a latitude variable or a longitude variable. Write one
member function to obtain an angle value (in degrees and minutes) and a direction from the user, and a second to
display the angle value in 179°59.9’ E format. Also write a three-argument constructor.
Write a main() program that displays an angle initialized with the constructor, and then, within a loop, allows the
user to input any angle value, and then displays the value. You can use the hex character constant ‘\xF8’, which
usually prints a degree (°) symbol. */

#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

class Location
{
    int degrees;
    float minutes;
    char direction;

public:
    Location(int degrees, float minutes, char direction)
    {
        this->degrees = degrees;
        this->minutes = minutes;
        this->direction = direction;
    }

    void setLocation()
    {
        do
        {
            cout << "Enter a valid direction (N for North, S for South, E for East, W for West): ";
            cin >> direction;
        } while (direction != 'N' && direction != 'S' && direction != 'E' && direction != 'W');

        do
        {
            cout << "Enter valid degrees (0 to 180 degrees for East and West & 0 to 90 degrees for North and South): ";
            cin >> degrees;
        } while (((direction == 'E' || direction == 'W') && (degrees<0 || degrees>180)) || ((direction == 'N' || direction == 'S') && (degrees<0 || degrees>90)));

        do
        {
            cout << "Enter valid minutes (0 to 60 minutes): ";
            cin >> minutes;
        } while (minutes < 0 || minutes >= 60);
    }

    void displayLocation()
    {
        cout << "The angle value is: " << degrees << "\xF8" << fixed << setprecision(1) << minutes << "\' " << direction << endl;
    }
};

int main()
{
    Location l1(0, 0, 'E');
    char choice;
    while (1)
    {
        cout << endl << "Entering angle value:" << endl;
        l1.setLocation();
        cout << endl << "Displaying the angle value:" << endl;
        l1.displayLocation();

        cout << "Press any key except the Esc key to continue; otherwise, press the Esc key to exit the program";
        choice = _getch();

        if (int(choice) == 27)
        {
            cout << endl << "Exiting the program...";
            break;
        }
    }
    return 0;
}