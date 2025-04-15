#include <iostream>
#include <memory>

using namespace std;

class Vehicle {
protected:
    string model;
    double rate;

public:
    Vehicle(const string& model, double rate) : model(model), rate(rate) {}
    virtual double getDailyRate() const = 0;
    virtual void displayDetails() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    Car(const string& model, double rate) : Vehicle(model, rate) {}

    double getDailyRate() const override {
        return rate;
    }

    void displayDetails() const override {
        cout << "Car Model: " << model << "\n";
        cout << "Daily Rate: $" << getDailyRate() << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(const string& model, double rate) : Vehicle(model, rate) {}

    double getDailyRate() const override {
        return rate;
    }

    void displayDetails() const override {
        cout << "Bike Model: " << model << "\n";
        cout << "Daily Rate: $" << getDailyRate() << endl;
    }
};

int main() {
    Vehicle* vehicles[2];

    vehicles[0] = new Car("Maruti Suzuki", 69.21);
    vehicles[1] = new Bike("Hero Honda", 420.23);

    for (int i = 0; i < 2; ++i) {
        vehicles[i]->displayDetails();
        cout << "-------------------\n";
    }

    for (int i = 0; i < 2; ++i) {
        delete vehicles[i];
    }

    return 0;
}

