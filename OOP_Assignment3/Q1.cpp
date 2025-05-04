#include <iostream>
#include <fstream>
using namespace std;

class AssignmentInfo {
    string fullName;
    string studentID;

public:
    AssignmentInfo() {
        fullName = "Zain Ul abideen Ahmad";
        studentID = "K24-0818";
    }

    void displayCreator() {
        cout << "\n\nThis assignment was completed by " << fullName << " (" << studentID << ")\n" << endl;
    }
};

int getValidatedInt(const string& prompt) {
    int num;
    while (true) {
        cout << prompt;
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
        } else {
            cin.ignore(1000, '\n');
            return num;
        }
    }
}

class Bus;

class Customer {
protected:
    int id;
    string fullName;
    bool paid;
    string start;
    string destination;
    int activeMonths;
    Bus* linkedBus;

public:
    Customer() : id(0), fullName(""), paid(false), start(""), destination(""), activeMonths(0), linkedBus(nullptr) {}

    Customer(int i, string n, bool p, string s, string d, int months) {
        id = i;
        fullName = n;
        paid = p;
        start = s;
        destination = d;
        activeMonths = months;
        linkedBus = nullptr;
    }

    virtual void printDetails() = 0;

    virtual void writeDataToFile(fstream& out) {
        out << id << '\n'
            << fullName << '\n'
            << paid << '\n'
            << start << '\n'
            << destination << '\n'
            << activeMonths << '\n';
    }

    virtual void readDataFromFile(fstream& in) {
        in >> id;
        in.ignore(); getline(in, fullName);
        in >> paid;
        in.ignore(); getline(in, start);
        getline(in, destination);
        in >> activeMonths;
    }

    int getId() const { return id; }

    string getName() const { return fullName; }

    void setName(const string& n) { fullName = n; }

    bool isPaid() const { return paid; }

    string getStart() const { return start; }

    string getDestination() const { return destination; }

    virtual void setPaid(bool p) { paid = p; }

    void setStart(const string& s) { start = s; }

    void setDestination(const string& d) { destination = d; }

    Bus* getLinkedBus() { return linkedBus; }

    void setLinkedBus(Bus* b) { linkedBus = b; }

    Bus* getAssignedBus();  // Added function prototype
};

class Student : public Customer {
public:
    Student() = default;

    Student(int i, string n, bool p, string s, string d)
        : Customer(i, n, p, s, d, 6) {}

    void setPaid(bool p) override {
        paid = p;
        activeMonths = 6;
    }

    void printDetails() override {
        cout << "\nStudent ID: " << id
             << "\nStudent Name: " << fullName
             << "\nPayment Status: " << (paid ? "Paid" : "Unpaid")
             << "\nPickup Stop: " << start
             << "\nDrop Stop: " << destination
             << "\nCard Validity: " << activeMonths << " months\n";
    }
};

class Teacher : public Customer {
public:
    Teacher() = default;

    Teacher(int i, string n, bool p, string s, string d)
        : Customer(i, n, p, s, d, 1) {}

    void setPaid(bool p) override {
        paid = p;
        if (p) activeMonths = 1;
    }

    void printDetails() override {
        cout << "\nTeacher ID: " << id
             << "\nTeacher Name: " << fullName
             << "\nPayment Status: " << (paid ? "Paid" : "Unpaid")
             << "\nPickup Stop: " << start
             << "\nDrop Stop: " << destination
             << "\nCard Validity: " << activeMonths << " months\n";
    }
};

class Bus {
    int busID;
    int capacity;
    string* routeStops;
    int assignedCount;
    int stopCount;

public:
    Bus() : busID(0), capacity(0), routeStops(nullptr), assignedCount(0), stopCount(0) {}

    Bus(int id, int cap, string* stops, int count)
        : busID(id), capacity(cap), stopCount(count), assignedCount(0) {
        routeStops = new string[stopCount];
        for (int i = 0; i < stopCount; ++i) {
            routeStops[i] = stops[i];
        }
    }

    Bus(const Bus& other)
        : busID(other.busID), capacity(other.capacity), stopCount(other.stopCount), assignedCount(other.assignedCount) {
        routeStops = new string[stopCount];
        for (int i = 0; i < stopCount; ++i) {
            routeStops[i] = other.routeStops[i];
        }
    }

    ~Bus() {
        delete[] routeStops;
    }

    void writeDataToFile(fstream& out) {
        out << busID << '\n'
            << capacity << '\n'
            << assignedCount << '\n'
            << stopCount << '\n';
        for (int i = 0; i < stopCount; ++i) {
            out << routeStops[i] << '\n';
        }
    }

    void readDataFromFile(fstream& in) {
        if (in.eof()) return;
        in >> busID >> capacity >> assignedCount >> stopCount;
        in.ignore();
        delete[] routeStops;
        routeStops = new string[stopCount];
        for (int i = 0; i < stopCount; ++i) {
            getline(in, routeStops[i]);
        }
    }

    void assignToCustomer(Customer* cust) {
        if (assignedCount >= capacity) {
            cout << "Bus is full. Cannot assign customer.\n";
            return;
        }

        bool pickupFound = false;
        bool dropFound = false;

        for (int i = 0; i < stopCount; ++i) {
            if (cust->getStart() == routeStops[i]) {
                pickupFound = true;
                break;
            }
        }

        for (int i = 0; i < stopCount; ++i) {
            if (cust->getDestination() == routeStops[i]) {
                dropFound = true;
                break;
            }
        }

        if (pickupFound && dropFound) {
            cust->setPaid(true);
            assignedCount++;
            cust->setLinkedBus(this);
            cout << "Customer " << cust->getName() << " assigned to Bus " << busID << endl;
        } else {
            cout << "Stop not found. Customer not assigned.\n";
        }
    }

    int getBusID() const { return busID; }
    int getCapacity() const { return capacity; }
    int getStopCount() const { return stopCount; }
    string* getRouteStops() const { return routeStops; }
    int getAssignedCount() const { return assignedCount; }

    void setCapacity(int cap) { capacity = cap; }
    void setBusID(int id) { busID = id; }
    void setStopCount(int count) { stopCount = count; }

    void setStops(string* stops, int count) {
        delete[] routeStops;
        stopCount = count;
        routeStops = new string[count];
        for (int i = 0; i < count; ++i) {
            routeStops[i] = stops[i];
        }
    }

    void printStops() const {
        for (int i = 0; i < stopCount; ++i) {
            cout << i + 1 << ". " << routeStops[i] << '\n';
        }
    }
};

class TransportManager {
    Customer** clients;
    Bus** fleet;
    int totalClients;
    int totalBuses;
    int studentCount;
    int teacherCount;

public:
    TransportManager() : clients(nullptr), fleet(nullptr), totalClients(0), totalBuses(0), studentCount(0), teacherCount(0) {}

    Customer** getClients() { return clients; }
    Bus** getFleet() { return fleet; }
    void setFleet(Bus** b) { fleet = b; }
    void setClients(Customer** c) { clients = c; }

    void loadMetaData() {
        fstream file("system.txt", ios::in);
        file >> totalBuses >> totalClients >> studentCount >> teacherCount;
        file.close();
    }

    void saveMetaData() {
        fstream file("system.txt", ios::out);
        file << totalBuses << '\n' << totalClients << '\n' << studentCount << '\n' << teacherCount;
        file.close();
    }

    void displayAllCustomers() {
        if (totalClients == 0) {
            cout << "No customer records.\n";
            return;
        }
        cout << "\nCustomer List:\n";
        for (int i = 0; i < totalClients; ++i) {
            clients[i]->printDetails();
        }
    }

    void displayAllBuses() {
        if (totalBuses == 0) {
            cout << "No bus records.\n";
            return;
        }
        cout << "\nBus List:\n";
        for (int i = 0; i < totalBuses; ++i) {
            cout << "Bus ID: " << fleet[i]->getBusID()
                 << ", Capacity: " << fleet[i]->getCapacity()
                 << ", Assigned: " << fleet[i]->getAssignedCount()
                 << ", Stops:";
            fleet[i]->printStops();
        }
    }

    void exportBusesToFile() {
        fstream out("bus.txt", ios::out);
        if (!out) {
            cout << "Could not open bus.txt for writing.\n";
            return;
        }
        for (int i = 0; i < totalBuses; ++i) {
            fleet[i]->writeDataToFile(out);
        }
        saveMetaData();
        out.close();
    }

    void importBusesFromFile() {
        fstream in("bus.txt", ios::in);
        loadMetaData();
        if (!in) {
            cout << "Could not open bus.txt for reading.\n";
            return;
        }

        fleet = new Bus*[totalBuses];
        for (int i = 0; i < totalBuses; ++i) {
            fleet[i] = new Bus();
            fleet[i]->readDataFromFile(in);
        }
        in.close();
    }

    void exportCustomersToFile() {
        fstream outStudents("student.txt", ios::out);
        fstream outTeachers("teacher.txt", ios::out);

        if (!outStudents || !outTeachers) {
            cout << "Error opening customer files for output.\n";
            return;
        }

        for (int i = 0; i < totalClients; ++i) {
            if (dynamic_cast<Student*>(clients[i])) {
                clients[i]->writeDataToFile(outStudents);
            } else if (dynamic_cast<Teacher*>(clients[i])) {
                clients[i]->writeDataToFile(outTeachers);
            }
        }
        saveMetaData();
    }

    void importCustomersFromFile() {
        loadMetaData();
        fstream inStudents("student.txt", ios::in);
        fstream inTeachers("teacher.txt", ios::in);

        if (!inStudents || !inTeachers) {
            cout << "Error opening customer files for input.\n";
            return;
        }

        clients = new Customer*[totalClients];

        for (int i = 0; i < studentCount; ++i) {
            clients[i] = new Student();
            clients[i]->readDataFromFile(inStudents);
        }

        for (int i = studentCount; i < (studentCount + teacherCount); ++i) {
            clients[i] = new Teacher();
            clients[i]->readDataFromFile(inTeachers);
        }

        displayAllCustomers();
    }

    void registerCustomer(const string& name, bool hasPaid, const string& from, const string& to, const string& role) {
        Customer** updated = new Customer*[totalClients + 1];

        for (int i = 0; i < totalClients; ++i)
            updated[i] = clients[i];

        if (role == "student") {
            updated[totalClients] = new Student(totalClients + 1, name, hasPaid, from, to);
            studentCount++;
        } else if (role == "teacher") {
            updated[totalClients] = new Teacher(totalClients + 1, name, hasPaid, from, to);
            teacherCount++;
        }

        delete[] clients;
        clients = updated;
        totalClients++;
    }

    void registerBus(int busId, int capacity, string* route, int stopsCount) {
        Bus** updated = new Bus*[totalBuses + 1];

        for (int i = 0; i < totalBuses; ++i)
            updated[i] = fleet[i];

        updated[totalBuses] = new Bus(busId, capacity, route, stopsCount);

        delete[] fleet;
        fleet = updated;
        totalBuses++;
    }
};


Bus* Customer::getAssignedBus() {
    if (linkedBus) {
        cout << "Assigned to Bus: " << linkedBus->getBusID() << endl;
        return linkedBus;
    } else {
        cout << "No bus assignment found.\n";
        return nullptr;
    }
}
int main() {
    TransportManager manager;

    manager.importCustomersFromFile();
    manager.importBusesFromFile();

    cout << "\n=== All Customers ===\n";
    manager.displayAllCustomers();

    cout << "\n=== All Buses ===\n";
    manager.displayAllBuses();

    cout << "\n=== Register New Customers ===\n";
    manager.registerCustomer("Alice Johnson", true, "Stop A", "Stop E", "student");
    manager.registerCustomer("Michael Davis", true, "Stop B", "Stop F", "teacher");

    cout << "\n=== Updated Customer List ===\n";
    manager.displayAllCustomers();

    string route[] = {"Stop A", "Stop B", "Stop C", "Stop D", "Stop E"};
    manager.registerBus(101, 40, route, 5);

    cout << "\n=== Updated Bus List ===\n";
    manager.displayAllBuses();

    Bus* bus = manager.getFleet()[0];
    Customer* customer = manager.getClients()[0];
    bus->assignToCustomer(customer);

    cout << "\n=== Customer's Assigned Bus ===\n";
    customer->getAssignedBus();

    manager.exportCustomersToFile();
    manager.exportBusesToFile();

    return 0;
}

