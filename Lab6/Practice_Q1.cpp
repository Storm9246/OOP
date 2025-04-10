/*
A power distribution company wants to automate its billing system. The company supplies electricity to residential, commercial, and industrial consumers. 
The billing system should calculate the monthly electricity bill based on different tariff rates for each consumer type.

Problem Statement:
The company has consumers who are categorized as follows:
1. Residential Consumers: Charged at $0.12 per unit.
2. Commercial Consumers: Charged at $0.20 per unit.
3. Industrial Consumers: Charged at $0.30 per unit.

Additionally:
--> If a residential consumer consumes more than 500 units, a surcharge of 5% is applied.
--> If a commercial consumer consumes more than 1000 units, a surcharge of 10% is applied.
--> If an industrial consumer consumes more than 2000 units, a surcharge of 15% is applied.

The system should allow:
--> Registering a consumer (with details like consumer name, ID, and units consumed).
--> Displaying the total bill based on category-wise calculations.

Implementation Requirements:
--> Create a base class Consumer with attributes like name, consumerID, and unitsConsumed.
--> Create derived classes ResidentialConsumer, CommercialConsumer, and IndustrialConsumer which inherit from Consumer.
--> Each derived class should have a method to calculate the bill based on the unit consumption and applicable surcharge.
--> Create a main() function to allow user input and display the calculated bill.
*/

#include <iostream>
using namespace std;

/* Abstract Base Class */
class Consumer{
protected: 
    string name;
    string consumerID;
    int unitsConsumed;
public:
    Consumer(string n, string id, int units) : name(n), consumerID(id), unitsConsumed(units) {}

    virtual double calculateBill() = 0; // Pure Virtual Function
    virtual void displayDetails(){
        cout << endl << "Displaying consumer details below" << endl;
        cout << "Consumer Name: " << name << endl;
        cout << "Consumer ID: " << consumerID << endl;
        cout << "Units Consumed: " << unitsConsumed << endl;
        cout << "Total Bill: $" << calculateBill() << endl;
    }
};

class ResidentialConsumer : public Consumer{
public:
    ResidentialConsumer(string n, string id, int units) : Consumer(n, id, units) {}

    double calculateBill() override {
        double bill = unitsConsumed * 0.12;
        return (unitsConsumed > 500) ? (bill * 1.05) : bill;
    }
};

class CommercialConsumer : public Consumer{
public:
    CommercialConsumer(string n, string id, int units) : Consumer(n, id, units) {}
    
    double calculateBill() override {
        double bill = unitsConsumed * 0.20;
        return (unitsConsumed > 1000) ? (bill * 1.10) : bill;
    }
};

class IndustrialConsumer : public Consumer{
public:
    IndustrialConsumer(string n, string id, int units) : Consumer(n, id, units) {}

    double calculateBill() override {
        double bill = unitsConsumed * 0.30;
        return (unitsConsumed > 2000) ? (bill * 1.15) : bill;
    }
};

int main(){
    string name, id;
    int units, choice;
    Consumer *c = nullptr;

    cout << "------- Power Distribution Billing System -------" << endl;
    cout << "Enter consumer name: ";
    getline(cin, name);
    cout << "Enter consumer ID: ";
    getline(cin, id);
    cout << "Enter the units consumed: ";
    cin >> units;
    cout << "Enter consumer type (1 for Residential, 2 for Commercial, 3 for Industrial): ";
    cin >> choice;

    switch(choice){
        case 1:
            c = new ResidentialConsumer(name, id, units);
            c->displayDetails();
            break;
            
        case 2:
            c = new CommercialConsumer(name, id, units);
            c->displayDetails();
            break;

        case 3:
            c = new IndustrialConsumer(name, id, units);
            c->displayDetails();
            break;

        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    if(c != nullptr){
        delete c;
    } 
    return 0;
}
