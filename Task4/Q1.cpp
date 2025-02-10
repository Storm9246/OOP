// TASK # 01
// You are building a student management system. Create a class `Student` to manage student records.
// Requirements:
// 1. Attributes:
//  `studentID` (int)
//  `name` (string)
//  `age` (int)
//  `grade` (char)
// 2. Define a default constructor that initializes `grade` to `'N'` (Not Assigned).
// 3. Define a parameterized constructor to initialize all attributes.
// 4. Add methods:
//  `promoteStudent()`: Upgrades the student's grade (e.g., from 'A' to 'B').
//  `isEligibleForScholarship()`: Returns `true` if the student's grade is 'A'.
//  `displayDetails()`: Displays the student's details.
// 5. Create a few `Student` objects and test the methods.


#include <iostream>

using namespace std;

class student
{
    private:
        int studentID;
        string name;
        int age;
        char grade;

    public:
        student()
        {
            grade = 'N';
        }
        student(int ID, string name, int age, char grade)
        {
            studentID = ID;
            this->name = name;
            this->age = age;
            this->grade = grade;
        }

        void promoteStudent()
        {
            if(grade != 'A')
            {
                grade = grade - 1;   
            }
        }

        bool isEligibleForScholarship()
        {
            if(grade == 'A')
            {
                return true;
            }
            return false;
        }

        void displayDetails()
        {
            cout << "ID: " << studentID << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Grade: " << grade << endl;
        }


};

int main()
{
    student s1;
    student s2(69,"Shamim",32,'B');
    string res;
    s2.promoteStudent();
    s2.promoteStudent();
    
    res = s2.isEligibleForScholarship();
    
    cout << "student 2: " << endl;
    s2.displayDetails();
    cout << "Student 2 is Eligible For Scholarship: " << res <<endl;
    cout << endl;
    cout<<"student 1: "<<endl;
    s1.displayDetails();
    

}
