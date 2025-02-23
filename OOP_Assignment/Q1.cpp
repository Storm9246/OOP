
#include <iostream>
#include <string>
using namespace std;

class Skill {
    string skillID, skillName, skillDescription;
public:
    Skill(string id = "", string name = "", string desc = "") : skillID(id), skillName(name), skillDescription(desc) {}
    void showSkillDetails() { cout << "[" << skillID << "] " << skillName << " - " << skillDescription << endl; }
    void updateSkillDescription(string newDesc) { skillDescription = newDesc; }
    string getSkillName() { return skillName; }
};

class Sport {
    string sportID, sportName, sportDescription;
    Skill** requiredSkills;
    int numSkills;
public:
    Sport(string id = "", string name = "", string desc = "", Skill** skills = nullptr, int n = 0) : sportID(id), sportName(name), sportDescription(desc), numSkills(n) {
        requiredSkills = new Skill*[numSkills];
        for (int i = 0; i < numSkills; i++) requiredSkills[i] = skills[i];
    }
    void addSkill(Skill* s) {
        Skill** temp = new Skill*[numSkills + 1];
        for (int i = 0; i < numSkills; i++) temp[i] = requiredSkills[i];
        temp[numSkills++] = s;
        delete[] requiredSkills;
        requiredSkills = temp;
    }
    void removeSkill(Skill* s) {
        int index = -1;
        for (int i = 0; i < numSkills; i++) if (requiredSkills[i]->getSkillName() == s->getSkillName()) index = i;
        if (index == -1) return;
        Skill** temp = new Skill*[numSkills - 1];
        for (int i = 0, j = 0; i < numSkills; i++) if (i != index) temp[j++] = requiredSkills[i];
        delete[] requiredSkills;
        requiredSkills = temp;
        numSkills--;
    }
    void displaySportDetails() {
        cout << "Sport: " << sportName << " - " << sportDescription << endl;
        for (int i = 0; i < numSkills; i++) requiredSkills[i]->showSkillDetails();
    }
    string getSportName() { return sportName; }
    ~Sport() { delete[] requiredSkills; }
};

class Mentor;

class Student {
    string studentID, studentName;
    int studentAge;
    Sport** sportsInterests;
    int numSports;
    Mentor* mentorAssigned;
public:
    Student(string id, string name, int age, Sport** sports, int num) : studentID(id), studentName(name), studentAge(age), sportsInterests(sports), numSports(num), mentorAssigned(nullptr) {}
    void registerForMentorship(Mentor* m);
    void viewMentorDetails();
    void updateSportsInterest(Sport* s) { sportsInterests[numSports++] = s; }
    void displayStudentDetails() { cout << "Student: " << studentName << " (" << studentID << ") - Age: " << studentAge << endl; }
    string getStudentName() { return studentName; }
};

class Mentor {
    string mentorID, mentorName;
    Sport** sportExpertise;
    int numSports, maxLearners, currentLearners;
    Student** assignedLearners;
public:
    Mentor(string id, string name, int nS, int maxL, Sport** sports) : mentorID(id), mentorName(name), numSports(nS), maxLearners(maxL), currentLearners(0) {
        sportExpertise = new Sport*[numSports];
        for (int i = 0; i < numSports; i++) sportExpertise[i] = sports[i];
        assignedLearners = new Student*[maxLearners];
    }
    bool assignLearner(Student* s) {
        if (currentLearners >= maxLearners) return false;
        assignedLearners[currentLearners++] = s;
        return true;
    }
    void removeLearner(Student* s) {
        int index = -1;
        for (int i = 0; i < currentLearners; i++) if (assignedLearners[i]->getStudentName() == s->getStudentName()) index = i;
        if (index == -1) return;
        for (int i = index; i < currentLearners - 1; i++) assignedLearners[i] = assignedLearners[i + 1];
        currentLearners--;
    }
    void viewLearners() {
        cout << "Mentor " << mentorName << "'s Students:" << endl;
        for (int i = 0; i < currentLearners; i++) assignedLearners[i]->displayStudentDetails();
    }
    void provideGuidance() { cout << "Keep pushing forward!" << endl; }
    void displayMentorDetails() { cout << "Mentor: " << mentorName << " (" << mentorID << ")" << endl; }
};

void Student::registerForMentorship(Mentor* m) {
    if (m->assignLearner(this)) mentorAssigned = m;
}
void Student::viewMentorDetails() { if (mentorAssigned) mentorAssigned->displayMentorDetails(); }

int main() {
    Skill skill1("S101", "Dribbling", "Ball control skill");
    Skill skill2("S102", "Shooting", "Accurate shooting technique");
    Skill* footballSkills[] = { &skill1, &skill2 };
    Sport football("SP201", "Football", "Team-based sport", footballSkills, 2);
    Sport* mentorSports[] = { &football };
    Mentor mentor1("M101", "Coach Alex", 1, 3, mentorSports);
    Sport* studentSports[] = { &football };
    Student student1("ST202", "John Doe", 19, studentSports, 1);
    
    int choice;
    do {
        cout << "\nMENU:\n1. Mentor Details\n2. Student Details\n3. View Learners\n4. Provide Guidance\n5. Add Skill\n6. Remove Skill\n7. Sport Details\n8. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: mentor1.displayMentorDetails(); break;
            case 2: student1.displayStudentDetails(); break;
            case 3: mentor1.viewLearners(); break;
            case 4: mentor1.provideGuidance(); break;
            case 5: {
                Skill* newSkill = new Skill("S103", "Passing", "Quick and accurate passing");
                football.addSkill(newSkill);
                break;
            }
            case 6: football.removeSkill(&skill1); break;
            case 7: football.displaySportDetails(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 8);
    return 0;
}
