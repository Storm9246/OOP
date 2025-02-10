// TASK # 04
// You are building a car rental system. Create a class `Car` to manage cars available for rent.
// Requirements:
// 1. Attributes:
//  `carID` (int)
//  `model` (string)
//  `year` (int)
//  `isRented` (bool)
// 2. Define a default constructor that initializes `isRented` to `false`.
// 3. Define a parameterized constructor to initialize all attributes.
// 4. Add methods:

//  `rentCar()`: Marks the car as rented.
//  `returnCar()`: Marks the car as available.
//  `isVintage()`: Returns `true` if the car's year is before 2000.

// 5. Create a few `Car` objects and test the methods.

#include <iostream>

using namespace std;

class Car
{
    private:
        int carId;
        string model;
        int year;
        bool isRented;
    
    public:
        Car()
        {
            isRented = false;
        }
        Car(int carId, string model, int year)
        {
            this->carId = carId;
            this->model = model;
            this->year = year;
            isRented = false;
        }

        void rentCar()
        {
            isRented = false;
            cout << "the car has been rented" << endl;
        }

        void returnCar()
        {
            isRented = true;
            cout << "the car has been returned" << endl;
        }

        bool isVintage()
        {
            if(year < 2000)
            {
                return true;
            }
            return false;
        }
};

int main()
{
    Car c1;
    Car c2(69,"412AE",2004);
    cout<<"Car 1"<<endl;
    c1.rentCar();
    c1.returnCar();
    cout<<"Is car vintage: "<<(c1.isVintage()?"YES":"NO");
    cout<<endl<<"Car 2"<<endl;
    c2.rentCar();
    c2.returnCar();
    cout<<"Is car vintage: "<<(c2.isVintage()?"YES":"NO");
}