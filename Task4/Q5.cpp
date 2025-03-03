/* You are building an employee management system. Create a class `Employee` to manage employee records.
Requirements:
1. Attributes:
    --> `employeeID` (int)
    --> `name` (string)
    --> `department` (string)
    --> `salary` (double)
2. Define a default constructor that initializes `salary` to `0.0`.
3. Define a parameterized constructor to initialize all attributes.
4. Add methods:
    --> `giveBonus(double amount)`: Adds the bonus amount to the employee's salary.
    --> `isManager()`: Returns `true` if the employee's department is "Management".
    --> `displayDetails()`: Displays the employee's details.
5. Create a few `Employee` objects and test the methods. */

#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
    int employeeID;
    string name;
    string department;
    double salary;

public:
    Employee()
    {
        employeeID = 0;
        name = "";
        department = "";
        salary = 0.0;
    }

    Employee(int employeeID, string name, string department, double salary)
    {
        this->employeeID = employeeID;
        this->name = name;
        this->department = department;
        this->salary = salary;
    }

    void giveBonus(double amount)
    {
        salary += amount;
        cout << endl << "Bonus has been added successfully." << endl;
    }

    bool isManager()
    {
        if (department == "Management")
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void displayDetails()
    {
        cout << endl << "Employee ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: $" << fixed << setprecision(2) << salary << endl;
    }
};

int main()
{
    Employee e1, e2, e3;

    e1 = Employee(687, "Rayyan Aamir", "Management", 20500.50);
    e1.giveBonus(4000);
    e1.displayDetails();
    cout << "Manager: " << (e1.isManager() ? "Yes" : "No") << endl;

    e2 = Employee(456, "Murtaza Hunaid", "Senior Dev", 15750.26);
    e2.giveBonus(5000);
    e2.displayDetails();
    cout << "Manager: " << (e2.isManager() ? "Yes" : "No") << endl;

    e3 = Employee(123, "Usman Hasan", "Junior Dev", 10670.78);
    e3.giveBonus(1000);
    e3.displayDetails();
    cout << "Manager: " << (e3.isManager() ? "Yes" : "No") << endl;

    return 0;
}