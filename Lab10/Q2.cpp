// Q2. A user wishes to update their resume in your Resume Builder application.
// Requirements:
// 1. Prompt the user to enter:
// ○ string name
// ○ string email
// ○ int yearsOfExperience
// ○ string summary
// 2. Write this data to a file called resume.txt.
// 3. Use ofstream with ios::trunc to ensure that any previous contents are completely
// deleted before writing new data.
// 4. After writing, read back and display the contents to confirm that the file only has the
// latest entry.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string name, email, summary;
    int yearsOfExperience;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your email: ";
    getline(cin, email);

    cout << "Enter your years of experience: ";
    cin >> yearsOfExperience;
    cin.ignore();

    cout << "Enter a brief summary: ";
    getline(cin, summary);

    ofstream outFile("resume.txt", ios::trunc);
    if (!outFile) {
        cerr << "Error: Could not open file for writing." << endl;
        return 1;
    }

    outFile << "Name: " << name << "\n"
            << "Email: " << email << "\n"
            << "Years of Experience: " << yearsOfExperience << "\n"
            << "Summary: " << summary << "\n";

    outFile.close();

    ifstream inFile("resume.txt");
    if (!inFile) {
        cerr << "Error: Could not open file for reading." << endl;
        return 1;
    }

    cout << "\n--- Resume Content ---\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
    return 0;
}
