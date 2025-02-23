#include <iostream>
#include <string>
using namespace std;

const int MAX_STOPS = 50;
const int MAX_STUDENTS = 100;
const int MAX_ROUTES = 10;
const int MAX_BUSES = 10;

class Student
{
    string studentID;
    string studentName;
    bool feesPaid;
    bool cardActive;
    string stopName;

public:
    Student() : studentID(""), studentName(""), feesPaid(false), cardActive(false), stopName("") {}
    Student(const string &id, const string &name) : studentID(id), studentName(name), feesPaid(false), cardActive(false), stopName("") {}

    string getStudentID() const { return studentID; }
    string getName() const { return studentName; }
    bool isCardActive() const { return cardActive; }
    bool isFeePaid() const { return feesPaid; }
    string getStopName() const { return stopName; }

    void setStopName(const string &stop) { stopName = stop; }
    void payFees()
    {
        feesPaid = true;
        cardActive = true;
        cout << "Fees paid. Card is now active for " << studentName << "." << endl;
    }

    void verifyCard() const
    {
        cout << "Card " << (cardActive ? "is active" : "is not active. Please pay fees.") << " for " << studentName << "." << endl;
    }
};

class Transportation
{
    string routeID;
    string routeName;
    string stops[MAX_STOPS];
    int numStops;

public:
    Transportation() : routeID(""), routeName(""), numStops(0) {}
    Transportation(const string &id, const string &name) : routeID(id), routeName(name), numStops(0) {}

    string getRouteID() const { return routeID; }
    string getRouteName() const { return routeName; }

    void addStop(const string &stop)
    {
        if (numStops < MAX_STOPS)
        {
            stops[numStops++] = stop;
            cout << "Stop \"" << stop << "\" has been added to route " << routeName << "." << endl;
        }
        else
        {
            cout << "Cannot add more stops. Maximum limit reached." << endl;
        }
    }

    void assignStudent(Student &student, const string &stop)
    {
        for (int i = 0; i < numStops; i++)
        {
            if (stops[i] == stop)
            {
                student.setStopName(stop);
                cout << "Student " << student.getName() << " assigned to stop \"" << stop << "\"." << endl;
                return;
            }
        }
        cout << "Stop \"" << stop << "\" not found in route " << routeName << "." << endl;
    }
};

class Bus
{
    string busID;
    string busName;
    Transportation *assignedRoute;

public:
    Bus() : busID(""), busName(""), assignedRoute(nullptr) {}
    Bus(const string &id, const string &name) : busID(id), busName(name), assignedRoute(nullptr) {}

    void assignRoute(Transportation &route)
    {
        assignedRoute = &route;
        cout << "Route \"" << route.getRouteName() << "\" assigned to bus " << busName << "." << endl;
    }

    void recordAttendance(const Student &student) const
    {
        cout << "Attendance " << (student.isCardActive() ? "recorded" : "not recorded, card inactive") << " for " << student.getName() << " on bus " << busName << "." << endl;
    }
};

int main()
{
    Student students[MAX_STUDENTS];
    Transportation routes[MAX_ROUTES];
    Bus buses[MAX_BUSES];

    int studentCount = 0, routeCount = 0, busCount = 0;
    int choice;

    do
    {
        cout << "\n========= TRANSPORTATION SYSTEM MENU =========" << endl;
        cout << "1. Register a Student\n2. Pay Fees\n3. Verify Card\n4. Create a Route\n5. Add Stop to Route" << endl;
        cout << "6. Assign Student to Stop\n7. Create a Bus\n8. Assign Route to Bus\n9. Record Attendance\n0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            if (studentCount < MAX_STUDENTS)
            {
                string id, name;
                cout << "Enter Student ID: ";
                getline(cin, id);
                cout << "Enter Student Name: ";
                getline(cin, name);
                students[studentCount++] = Student(id, name);
                cout << "Student " << name << " registered successfully." << endl;
            }
            else
                cout << "Maximum student limit reached." << endl;
            break;

        case 2:
        case 3:
        case 6:
        case 9:
            {
                string id;
                cout << "Enter Student ID: ";
                getline(cin, id);
                bool found = false;
                for (int i = 0; i < studentCount; i++)
                {
                    if (students[i].getStudentID() == id)
                    {
                        if (choice == 2)
                            students[i].payFees();
                        else if (choice == 3)
                            students[i].verifyCard();
                        found = true;
                        break;
                    }
                }
                if (!found)
                    cout << "Student not found!" << endl;
            }
            break;

        case 4:
            if (routeCount < MAX_ROUTES)
            {
                string id, name;
                cout << "Enter Route ID: ";
                getline(cin, id);
                cout << "Enter Route Name: ";
                getline(cin, name);
                routes[routeCount++] = Transportation(id, name);
                cout << "Route created successfully." << endl;
            }
            else
                cout << "Maximum routes reached." << endl;
            break;

        case 7:
            if (busCount < MAX_BUSES)
            {
                string id, name;
                cout << "Enter Bus ID: ";
                getline(cin, id);
                cout << "Enter Bus Name: ";
                getline(cin, name);
                buses[busCount++] = Bus(id, name);
                cout << "Bus created successfully." << endl;
            }
            else
                cout << "Maximum buses reached." << endl;
            break;

        case 0:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
