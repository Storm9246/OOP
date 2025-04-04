#include <iostream>
using namespace std;

class User
{
protected:
    string userID;
    string userName;
    string stopName;
    bool isCardActive;

public:
    User(string id, string n, string stop, bool card = true) : userID(id), userName(n), stopName(stop), isCardActive(card) {}

    virtual void payFees() = 0;

    void updateStop(string stop)
    {
        this->stopName = stop;
        cout << "Stop updated successfully to " << stopName << endl;
    }

    virtual void displayUserInfo() const
    {
        cout << endl << "User Name: " << userName << endl;
        cout << "User ID: " << userID << endl;
        cout << "User's Stop Name: " << stopName << endl;
        cout << "Card: " << ((isCardActive) ? "Active" : "Not Active") << endl;
    }

    string getUserID() const { return userID; }
    string getUserName() const { return userName; }
    string getStopName() const { return stopName; }
    bool getIsCardActive() const { return isCardActive; }

    virtual ~User() {}
};

class Student : public User
{
    bool attendanceList[31];

public:
    Student(string id, string n, string stop, bool card = true) : User(id, n, stop, card)
    {
        for (int i = 0; i < 31; i++)
        {
            attendanceList[i] = false;
        }
    }

    void payFees() override
    {
        isCardActive = true;
        cout << "Transport semester fees paid successfully for student: " << userName << endl;
    }

    void recordAttendance(int day)
    {
        if (day < 1 || day > 31)
        {
            cout << "Invalid input! Enter a day between 1 and 31." << endl;
            return;
        }

        if (isCardActive)
        {
            attendanceList[day - 1] = true;
            cout << "Attendance marked for " << userName << " on day " << day << endl;
        }
        else
        {
            cout << "Attendance cannot be marked as card is inactive for " << userName << ". Kindly pay the transport fees to activate the card." << endl;
        }
    }

    void displayAttendance() const
    {
        if (!isCardActive)
        {
            cout << "Card is inactive for " << userName << ". Kindly pay the transport fees to activate the card." << endl;
            return;
        }

        cout << endl << "Displaying attendance for " << userName << endl;
        for (int i = 0; i < 31; i++)
        {
            cout << "Day " << (i + 1) << ": " << ((attendanceList[i]) ? "Present" : "Absent") << endl;
        }
    }
};

class Teacher : public User
{
public:
    Teacher(string id, string n, string stop, bool card = true) : User(id, n, stop, card) {}

    void payFees() override
    {
        cout << "Transport monthly fees paid successfully for teacher: " << userName << endl;
    }
};

class Staff : public User
{
public:
    Staff(string id, string n, string stop, bool card = true) : User(id, n, stop, card) {}

    void payFees() override
    {
        cout << "Transport weekly fees paid successfully for staff: " << userName << endl;
    }
};


class Bus
{
    string busID, busName;
    string *stops;
    int numStops;
    const int maxStops;

public:
    Bus(string id, string n, int mStops) : busID(id), busName(n), maxStops(mStops), numStops(0), stops(new string[maxStops]) {}

    ~Bus() { delete[] stops; }

    void addStop(const string &stopName)
    {
        if (numStops < maxStops)
        {
            stops[numStops++] = stopName;
            cout << "Added stop: " << stopName << " to " << busName << " (" << busID << ")." << endl;
        }
        else
        {
            cout << "Cannot add stop. " << busName << " (" << busID << ") has reached max stops." << endl;
        }
    }

    void removeStop(const string &stopName)
    {
        for (int i = 0; i < numStops; i++)
        {
            if (stops[i] == stopName)
            {
                for (int j = i; j < numStops - 1; j++)
                {
                    stops[j] = stops[j + 1];
                }
                numStops--;
                cout << "Removed stop: " << stopName << " from " << busName << "'s route." << endl;
                return;
            }
        }
        cout << "Stop: " << stopName << " not found in " << busName << "'s route." << endl;
    }

    void displayBusInfo() const
    {
        cout << "\nBus Name: " << busName << "\nBus ID: " << busID << "\nNumber of Stops: " << numStops << endl;
        for (int i = 0; i < numStops; i++)
        {
            cout << "Stop " << (i + 1) << ": " << stops[i] << endl;
        }
    }

    bool operator==(const Bus &other) const
    {
        if (numStops != other.numStops)
            return false;
        for (int i = 0; i < numStops; i++)
            if (stops[i] != other.stops[i])
                return false;
        return true;
    }

    string getBusID() const { return busID; }
};

class Transportation
{
    User **users;
    int numUsers, maxUsers;
    Bus **buses;
    int numBuses, maxBuses;
    static int totalUsers;

public:
    Transportation(int mUsers, int mBuses) : users(new User *[mUsers]), buses(new Bus *[mBuses]),
                                             numUsers(0), maxUsers(mUsers), numBuses(0), maxBuses(mBuses) {}

    void registerUser()
    {
        if (numUsers == maxUsers)
        {
            cout << "User registration limit reached!" << endl;
            return;
        }

        string userType, id, userName, stopName;
        cout << "Enter the type of user (student, teacher, staff): ";
        getline(cin, userType);
        cout << "Enter the ID of user: ";
        getline(cin, id);
        cout << "Enter the name of user: ";
        getline(cin, userName);
        cout << "Enter the stop name of user: ";
        getline(cin, stopName);

        if (userType == "student")
            users[numUsers++] = new Student(id, userName, stopName);
        else if (userType == "teacher")
            users[numUsers++] = new Teacher(id, userName, stopName);
        else if (userType == "staff")
            users[numUsers++] = new Staff(id, userName, stopName);
        else
        {
            cout << "Invalid user type entered." << endl;
            return;
        }

        totalUsers++;
        cout << userName << " has been registered successfully!" << endl;
    }

    void addBus()
    {
        if (numBuses == maxBuses)
        {
            cout << "Bus limit reached!" << endl;
            return;
        }

        string id, busName;
        int maxStops;
        cout << "Enter the id of bus: ";
        getline(cin, id);
        cout << "Enter the name of bus: ";
        getline(cin, busName);
        cout << "Enter the maximum stops of the bus: ";
        cin >> maxStops;
        cin.ignore();

        buses[numBuses++] = new Bus(id, busName, maxStops);
        cout << "Bus: " << busName << " has been added successfully!" << endl;
    }

    void displayAllUsers() const
    {
        for (int i = 0; i < numUsers; ++i)
        {
            users[i]->displayUserInfo();
        }
    }

    void displayAllBuses() const
    {
        for (int i = 0; i < numBuses; ++i)
        {
            buses[i]->displayBusInfo();
        }
    }

    void defineStops()
    {
        string id;
        cout << "Enter the ID of the bus to define stops for: ";
        getline(cin, id);

        Bus *targetBus = nullptr;
        for (int i = 0; i < numBuses; ++i)
        {
            if (buses[i]->getBusID() == id)
            {
                targetBus = buses[i];
                break;
            }
        }

        if (!targetBus)
        {
            cout << "Bus ID not found!" << endl;
            return;
        }

        int n;
        cout << "Enter the number of stops to be defined: ";
        cin >> n;
        cin.ignore();

        for (int j = 0; j < n; ++j)
        {
            string stop;
            cout << "Enter stop " << (j + 1) << ": ";
            getline(cin, stop);
            targetBus->addStop(stop);
        }

        cout << "Stops defined for bus ID: " << id << " successfully." << endl;
    }

    static int getTotalUser()
    {
        return totalUsers;
    }

    ~Transportation()
    {
        for (int i = 0; i < numUsers; ++i)
            delete users[i];
        delete[] users;

        for (int i = 0; i < numBuses; ++i)
            delete buses[i];
        delete[] buses;
    }
};

int Transportation::totalUsers = 0;


int main()
{
    Transportation transportSystem(5, 3);

    while (true)
    {
        cout << "\n===== TRANSPORTATION MANAGEMENT SYSTEM =====\n";
        cout << "1. Register User\n";
        cout << "2. Add Bus\n";
        cout << "3. Define Stops for a Bus\n";
        cout << "4. Display All Users\n";
        cout << "5. Display All Buses\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        switch (choice)
        {
        case 1:
            transportSystem.registerUser();
            break;
        case 2:
            transportSystem.addBus();
            break;
        case 3:
            transportSystem.defineStops();
            break;
        case 4:
            transportSystem.displayAllUsers();
            break;
        case 5:
            transportSystem.displayAllBuses();
            break;
        case 6:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    }
}

