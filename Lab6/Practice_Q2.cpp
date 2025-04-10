/*
A city’s Traffic Control Authority wants to implement an automated fine management system to track traffic violations and calculate penalties based on the type of vehicle.
The system should differentiate between cars, bikes, and trucks, applying different fine structures for violations.

Problem Statement:
The system should categorize vehicles into three types:
1. Cars
 - Speed Limit: 80 km/h
 - Fine Rate: $5 per km/h over the limit
 - Additional Fine: If speed exceeds 120 km/h, impose a 10% surcharge
2. Bikes
 - Speed Limit: 60 km/h
 - Fine Rate: $3 per km/h over the limit
 - Additional Fine: If speed exceeds 90 km/h, impose a 15% surcharge
3. Trucks
 - Speed Limit: 70 km/h
 - Fine Rate: $7 per km/h over the limit
 - Additional Fine: If speed exceeds 100 km/h, impose a 20% surcharge

The system should:
--> Allow vehicle registration (Owner Name, Vehicle ID, Vehicle Type).
--> Record a speed violation (input actual speed).
--> Calculate the total fine based on the vehicle type and excess speed.
--> Apply additional surcharge for extreme overspeeding.
--> Display violation details and the fine amount.

Implementation Requirements:
--> Create a base class Vehicle with common attributes: ownerName, vehicleID, speed.
--> Derive three classes: Car, Bike, and Truck from Vehicle.
--> Each derived class should override a method to calculateFine(), applying specific fine rates and surcharges.
--> Implement a user interface in main() to allow entering vehicle details, recording violations, and displaying fine details.
*/

#include <iostream>
using namespace std;

class Vehicle{
protected:  
    string ownerName;
    string vehicleID;
    int speed;

public:
    Vehicle(string n, string id, int s) : ownerName(n), vehicleID(id), speed(s) {}

    virtual double calculateFine() = 0;
    virtual void displayDetails(){
        cout << endl << "Traffic Violation Details:" << endl;
        cout << "--------------------------" << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Vehicle ID: " << vehicleID << endl;
    }
};

class Car : public Vehicle{
    const int speedLimit = 80;
    const int fineRate = 5;
    const int surchargeLimit = 120;
    const double surchargeRate = 0.10;

public:
    Car(string n, string id, int s) : Vehicle(n, id, s) {}

    double calculateFine() override {
        if(speed <= speedLimit){
            return 0;
        }

        double fine = (speed - speedLimit) * fineRate;
        if(speed > surchargeLimit){
            fine *= (1 + surchargeRate);
        }

        return fine;
    }

    void displayDetails() override {
        Vehicle :: displayDetails();
        cout << "Vehicle Type: Car" << endl;
        cout << "Speed Recorded: " << speed << " km/h" << endl;
        cout << "Speed Limit: " << speedLimit << " km/h" << endl;

        int excessSpeed = speed - speedLimit;
        if(excessSpeed <= 0){
            cout << "No violations. Total Fine = $0" << endl;
            return;
        }

        cout << "Over-speeding: " << excessSpeed << " km/h" << endl;
        cout << "Base Fine: $" << (excessSpeed * fineRate) << endl;
        if(speed > surchargeLimit){
            cout << "Surcharge (" << (surchargeRate * 100) << "% for extreme speeding) applied: $" << ((excessSpeed * fineRate) * surchargeRate) << endl;
        }

        cout << "Total Fine: $" << calculateFine() << endl;
    }
};

class Bike : public Vehicle{
    const int speedLimit = 60;
    const int fineRate = 3;
    const int surchargeLimit = 90;
    const double surchargeRate = 0.15;

public:
    Bike(string n, string id, int s) : Vehicle(n, id, s) {}

    double calculateFine() override {
        if(speed <= speedLimit){
            return 0;
        }

        double fine = (speed - speedLimit) * fineRate;
        if(speed > surchargeLimit){
            fine *= (1 + surchargeRate);
        }

        return fine;
    }

    void displayDetails() override {
        Vehicle :: displayDetails();
        cout << "Vehicle Type: Bike" << endl;
        cout << "Speed Recorded: " << speed << " km/h" << endl;
        cout << "Speed Limit: " << speedLimit << " km/h" << endl;

        int excessSpeed = speed - speedLimit;
        if(excessSpeed <= 0){
            cout << "No violations. Total Fine = $0" << endl;
            return;
        }

        cout << "Over-speeding: " << excessSpeed << " km/h" << endl;
        cout << "Base Fine: $" << (excessSpeed * fineRate) << endl;
        if(speed > surchargeLimit){
            cout << "Surcharge (" << (surchargeRate * 100) << "% for extreme speeding) applied: $" << ((excessSpeed * fineRate) * surchargeRate) << endl;
        }

        cout << "Total Fine: $" << calculateFine() << endl;
    }
};

class Truck : public Vehicle{
    const int speedLimit = 70;
    const int fineRate = 7;
    const int surchargeLimit = 100;
    const double surchargeRate = 0.20;

public:
    Truck(string n, string id, int s) : Vehicle(n, id, s) {}

    double calculateFine() override {
        if(speed <= speedLimit){
            return 0;
        }

        double fine = (speed - speedLimit) * fineRate;
        if(speed > surchargeLimit){
            fine *= (1 + surchargeRate);
        }

        return fine;
    }

    void displayDetails() override {
        Vehicle :: displayDetails();
        cout << "Vehicle Type: Truck" << endl;
        cout << "Speed Recorded: " << speed << " km/h" << endl;
        cout << "Speed Limit: " << speedLimit << " km/h" << endl;

        int excessSpeed = speed - speedLimit;
        if(excessSpeed <= 0){
            cout << "No violations. Total Fine = $0" << endl;
            return;
        }

        cout << "Over-speeding: " << excessSpeed << " km/h" << endl;
        cout << "Base Fine: $" << (excessSpeed * fineRate) << endl;
        if(speed > surchargeLimit){
            cout << "Surcharge (" << (surchargeRate * 100) << "% for extreme speeding) applied: $" << ((excessSpeed * fineRate) * surchargeRate) << endl;
        }

        cout << "Total Fine: $" << calculateFine() << endl;
    }
};

int main(){
    string name, id;
    int speed, type;
    Vehicle *v = nullptr;

    cout << "Enter owner name: ";
    getline(cin, name);
    cout << "Enter vehicle ID: ";
    getline(cin, id);
    cout << "Select vehicle type (1: Car, 2: Bike, 3: Truck): ";
    cin >> type;
    cout << "Enter the speed of the vehicle (in km/h): ";
    cin >> speed;

    switch(type){
        case 1:
            v = new Car(name, id, speed);
            v->displayDetails();
            break;

        case 2:
            v = new Bike(name, id, speed);
            v->displayDetails();
            break;

        case 3:
            v = new Truck(name, id, speed);
            v->displayDetails();
            break;

        default:
            cout << "Invalid vehicle type entered!" << endl;
            return 1;
    }

    if(v != nullptr){
        delete v;
    }
    return 0;
}
