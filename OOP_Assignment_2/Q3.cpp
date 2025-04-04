#include <iostream>
using namespace std;

class Vehicle
{
protected:
    string vehicleID;
    double speed;
    double capacity;
    double energyEfficiency;
    static int activeDeliveries;

public:
    Vehicle(string id, double s, double c, double e)
        : vehicleID(id), speed(s), capacity(c), energyEfficiency(e)
    {
        ++activeDeliveries;
    }

    virtual ~Vehicle() {}

    static int getActiveDeliveries()
    {
        return activeDeliveries;
    }

    virtual double estimatedDeliveryTime(double distance) = 0;
    virtual void optimalDeliveryRoute() = 0;

    virtual void command(const string &command, const string &packageID) {}
    virtual void command(const string &command, const string &packageID, const string &urgencyLevel) {}

    friend bool operator==(const Vehicle &v1, const Vehicle &v2)
    {
        return v1.speed == v2.speed &&
               v1.capacity == v2.capacity &&
               v1.energyEfficiency == v2.energyEfficiency;
    }

    friend void resolveConflict(const Vehicle &, const Vehicle &);
};

int Vehicle::activeDeliveries = 0;

class RamzanDrone : public Vehicle
{
public:
    RamzanDrone(string id, double s, double c, double e)
        : Vehicle(id, s, c, e) {}

    double estimatedDeliveryTime(double distance) override
    {
        cout << "Drone " << vehicleID << " calculating aerial route time..." << endl;
        return distance / speed;
    }

    void optimalDeliveryRoute() override
    {
        cout << "Drone " << vehicleID << " planning aerial delivery route..." << endl;
    }

    void command(const string &command, const string &packageID) override
    {
        if (command == "Deliver")
            cout << "Drone " << vehicleID << " delivering " << packageID << endl;
        else if (command == "Pick-up")
            cout << "Drone " << vehicleID << " picking up " << packageID << endl;
    }

    void command(const string &command, const string &packageID, const string &urgencyLevel) override
    {
        if (command == "Deliver")
        {
            if (urgencyLevel == "High")
                cout << "Drone delivering " << packageID << " quickly for Iftar." << endl;
            else
                cout << "Drone " << vehicleID << " delivering " << packageID << " in normal mode." << endl;
        }
        else if (command == "Pick-up")
        {
            cout << "Drone " << vehicleID << " picking up " << packageID << endl;
        }
    }
};

class RamzanTimeShip : public Vehicle
{
public:
    RamzanTimeShip(string id, double s, double c, double e)
        : Vehicle(id, s, c, e) {}

    double estimatedDeliveryTime(double distance) override
    {
        cout << "Time Ship " << vehicleID << " managing time-sensitive route..." << endl;
        return distance / speed;
    }

    void optimalDeliveryRoute() override
    {
        cout << "Time Ship " << vehicleID << " plotting historical delivery course..." << endl;
    }

    void command(const string &command, const string &packageID) override
    {
        if (command == "Deliver")
            cout << "Time Ship " << vehicleID << " delivering " << packageID << endl;
        else if (command == "Pick-up")
            cout << "Time Ship " << vehicleID << " picking up " << packageID << endl;
    }

    void command(const string &command, const string &packageID, const string &urgencyLevel) override
    {
        if (command == "Deliver")
        {
            if (urgencyLevel == "High")
                cout << "Time Ship " << vehicleID << " delivering urgent package " << packageID << " for Iftar." << endl;
            else
                cout << "Time Ship " << vehicleID << " handling delivery of " << packageID << " at regular speed." << endl;
        }
        else if (command == "Pick-up")
        {
            cout << "Time Ship " << vehicleID << " retrieving " << packageID << endl;
        }
    }
};

class RamzanHyperPod : public Vehicle
{
public:
    RamzanHyperPod(string id, double s, double c, double e)
        : Vehicle(id, s, c, e) {}

    double estimatedDeliveryTime(double distance) override
    {
        cout << "Navigating underground tunnel network for Hyper Pod "
             << vehicleID << "..." << endl;
        return distance / speed;
    }

    void optimalDeliveryRoute() override
    {
        cout << "Deciding optimal route for bulk transport for Hyper Pod "
             << vehicleID << endl;
    }

    void command(const string &command, const string &packageID) override
    {
        if (command == "Deliver")
        {
            cout << "Hyper Pod " << vehicleID << " delivering package " << packageID << endl;
        }
        else if (command == "Pick-up")
        {
            cout << "Hyper Pod " << vehicleID << " picking up package " << packageID << endl;
        }
    }

    void command(const string &command, const string &packageID, const string &urgencyLevel) override
    {
        if (command == "Deliver")
        {
            cout << "Hyper Pod " << vehicleID << " "
                 << (urgencyLevel == "High" ? "prioritizing bulk delivery for package "
                                              : "delivering package ")
                 << packageID << (urgencyLevel == "High" ? "." : " in standard mode.") << endl;
        }
        else if (command == "Pick-up")
        {
            cout << "Hyper Pod " << vehicleID << " picking up package " << packageID << endl;
        }
    }
};

void resolveConflict(const Vehicle &v1, const Vehicle &v2)
{
    if (v1.energyEfficiency > v2.energyEfficiency)
    {
        cout << "Vehicle " << v1.vehicleID << " is chosen for delivery." << endl;
    }
    else if (v1.energyEfficiency < v2.energyEfficiency)
    {
        cout << "Vehicle " << v2.vehicleID << " is chosen for delivery." << endl;
    }
    else
    {
        cout << "Both vehicles have the same efficiency. Additional criteria needed." << endl;
    }
}


int main()
{
    RamzanDrone drone1("DR-007", 120.0, 5.0, 0.85);
    RamzanTimeShip ship1("TS-1995", 90.0, 15.0, 0.80);
    RamzanHyperPod pod1("HP-3000", 300.0, 50.0, 0.75);

    cout << "\n--- Testing Estimated Delivery Time ---\n";
    cout << "Drone ETA: " << drone1.estimatedDeliveryTime(240) << " hrs\n";
    cout << "Time Ship ETA: " << ship1.estimatedDeliveryTime(180) << " hrs\n";
    cout << "Hyper Pod ETA: " << pod1.estimatedDeliveryTime(600) << " hrs\n";

    cout << "\n--- Testing Optimal Delivery Routes ---\n";
    drone1.optimalDeliveryRoute();
    ship1.optimalDeliveryRoute();
    pod1.optimalDeliveryRoute();

    cout << "\n--- Testing Command (Standard) ---\n";
    drone1.command("Deliver", "PKG101");
    ship1.command("Pick-up", "PKG202");
    pod1.command("Deliver", "PKG303");

    cout << "\n--- Testing Command (With Urgency Level) ---\n";
    drone1.command("Deliver", "PKG101", "High");
    ship1.command("Deliver", "PKG202", "Low");
    pod1.command("Deliver", "PKG303", "High");

    cout << "\n--- Testing Operator Overload '==' ---\n";
    RamzanDrone drone2("DR-009", 120.0, 5.0, 0.85);
    cout << "Drone1 == Drone2? " << (drone1 == drone2 ? "Yes" : "No") << endl;

    cout << "\n--- Testing Static Member ActiveDeliveries ---\n";
    cout << "Active Deliveries: " << Vehicle::getActiveDeliveries() << endl;

    cout << "\n--- Testing Conflict Resolution ---\n";
    resolveConflict(ship1, pod1);

    return 0;
}
