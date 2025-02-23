#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string name, licenseType, contact, userID;
    int age;

public:
    User() : name(""), age(-1), licenseType(""), contact(""), userID("") {}

    void registerUser() {
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter License Type (Learner, Intermediate, Full): ";
        getline(cin, licenseType);
        cout << "Enter Contact Number: ";
        getline(cin, contact);
        cout << "Enter User ID: ";
        getline(cin, userID);
        cout << "User successfully registered!" << endl;
    }

    void updateUser() {
        if (age == -1) {
            cout << "No registered user found." << endl;
            return;
        }
        cin.ignore();
        cout << "Update Name: ";
        getline(cin, name);
        cout << "Update Age: ";
        cin >> age;
        cin.ignore();
        cout << "Update License Type: ";
        getline(cin, licenseType);
        cout << "Update Contact Number: ";
        getline(cin, contact);
        cout << "Update User ID: ";
        getline(cin, userID);
        cout << "User details updated successfully." << endl;
    }

    string getLicenseType() { return licenseType; }
};

class Vehicle {
private:
    string model, eligibility;
    float rentalPricePerDay;

public:
    Vehicle(string m, float rp, string e) : model(m), rentalPricePerDay(rp), eligibility(e) {}

    void displayVehicle() {
        cout << "Model: " << model << "\nRental Price per day: $" << rentalPricePerDay << "\nEligibility: " << eligibility << "\n" << endl;
    }

    bool isEligible(const string &licenseType) {
        int userLevel = (licenseType == "Full") ? 3 : (licenseType == "Intermediate") ? 2 : 1;
        int vehicleLevel = (eligibility == "Full") ? 3 : (eligibility == "Intermediate") ? 2 : 1;
        return userLevel >= vehicleLevel;
    }

    string getModel() { return model; }
};

int main() {
    User user;
    int vehicleCount;
    cout << "Enter number of vehicles: ";
    cin >> vehicleCount;
    Vehicle **vehicles = new Vehicle *[vehicleCount];

    for (int i = 0; i < vehicleCount; i++) {
        string model, eligibility;
        float price;
        cin.ignore();
        cout << "Enter Model: ";
        getline(cin, model);
        cout << "Enter Rental Price: ";
        cin >> price;
        cin.ignore();
        cout << "Enter Eligibility (Learner, Intermediate, Full): ";
        getline(cin, eligibility);
        vehicles[i] = new Vehicle(model, price, eligibility);
    }

    int choice;
    do {
        cout << "\n-------- Rent A Car Menu --------" << endl;
        cout << "1. Register User\n2. Update User Details\n3. View Available Vehicles\n4. Rent a Vehicle\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            user.registerUser();
            break;
        case 2:
            user.updateUser();
            break;
        case 3:
            for (int i = 0; i < vehicleCount; i++) {
                cout << "Vehicle " << (i + 1) << " Details:" << endl;
                vehicles[i]->displayVehicle();
            }
            break;
        case 4: {
            string model;
            cin.ignore();
            cout << "Enter the vehicle model to rent: ";
            getline(cin, model);
            bool found = false;
            for (int i = 0; i < vehicleCount; i++) {
                if (vehicles[i]->getModel() == model) {
                    found = true;
                    if (vehicles[i]->isEligible(user.getLicenseType())) {
                        cout << "Successfully rented " << model << "!" << endl;
                    } else {
                        cout << "You are not eligible to rent " << model << "!" << endl;
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Invalid vehicle model entered." << endl;
            }
            break;
        }
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 5);

    for (int i = 0; i < vehicleCount; i++) {
        delete vehicles[i];
    }
    delete[] vehicles;

    return 0;
}
