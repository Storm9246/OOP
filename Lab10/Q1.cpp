// Q1. You are building a student record management tool for a university system.
// Requirements:
// 1. Define a structure Student with the following fields:
// ○ int id
// ○ string name
// ○ float gpa
// 2. Prompt the user to enter data for 5 students.
// 3. Write these records to a file named students.txt using ofstream with ios::out
// mode.
// 4. Then, allow the user to append 1 additional student record using ios::app mode
// (open in append mode and write without erasing old content).
// 5. Finally, read and display all student records from the file using ifstream.


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float gpa;
};

void writeStudentToFile(ofstream &file, const Student &s) {
    file << s.id << " " << s.name << " " << s.gpa << endl;
}

void readStudentsFromFile(const string &filename) {
    ifstream inFile(filename);
    Student s;
    cout << "\n--- All Student Records ---\n";
    while (inFile >> s.id >> s.name >> s.gpa) {
        cout << "ID: " << s.id << ", Name: " << s.name << ", GPA: " << s.gpa << endl;
    }
    inFile.close();
}

int main() {
    const string filename = "students.txt";
    Student students[5];

    cout << "Enter data for 5 students:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Student " << i + 1 << " ID: ";
        cin >> students[i].id;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "GPA: ";
        cin >> students[i].gpa;
    }

    ofstream outFile(filename, ios::out);
    for (int i = 0; i < 5; ++i) {
        writeStudentToFile(outFile, students[i]);
    }
    outFile.close();

    Student newStudent;
    cout << "\nEnter data for 1 additional student:\n";
    cout << "ID: ";
    cin >> newStudent.id;
    cout << "Name: ";
    cin >> newStudent.name;
    cout << "GPA: ";
    cin >> newStudent.gpa;

    ofstream appendFile(filename, ios::app);
    writeStudentToFile(appendFile, newStudent);
    appendFile.close();

    readStudentsFromFile(filename);

    return 0;
}

