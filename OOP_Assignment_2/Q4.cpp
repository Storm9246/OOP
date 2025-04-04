#include <iostream>
using namespace std;

#define MAX_PERMISSIONS 20
#define MAX_ASSIGNMENTS 5
#define MAX_PROJECTS 2

long int generateHash(const string &password)
{
    long int hash = 5381;
    for (char ch : password)
    {
        hash = ((hash << 5) + hash) + ch;
    }
    return hash;
}

class User
{
protected:
    string name, id, email;
    long int hashed_password;
    string permissions[MAX_PERMISSIONS];
    int numPermissions = 0;

public:
    User(string n, string i, string e, string p)
        : name(n), id(i), email(e), hashed_password(generateHash(p)) {}

    virtual void addPermissions(const string &perm)
    {
        if (numPermissions < MAX_PERMISSIONS)
        {
            permissions[numPermissions++] = perm;
            cout << "\"" << perm << "\" granted to user: " << name << endl;
        }
        else
        {
            cout << "Permission capacity reached for user: " << name << endl;
        }
    }

    virtual bool authenticate(const string &password)
    {
        return generateHash(password) == hashed_password;
    }

    virtual void display()
    {
        cout << "\n--------- User Details ---------\n";
        cout << "Name: " << name << " | ID: " << id << " | Email: " << email << "\nPermissions:\n";
        for (int i = 0; i < numPermissions; ++i)
        {
            cout << "\t" << (i + 1) << ". " << permissions[i] << endl;
        }
    }

    virtual bool accessLab()
    {
        for (int i = 0; i < numPermissions; ++i)
        {
            if (permissions[i] == "access lab") return true;
        }
        return false;
    }

    virtual bool hasPermission(const string &perm)
    {
        for (int i = 0; i < numPermissions; ++i)
        {
            if (permissions[i] == perm) return true;
        }
        return false;
    }

    string getName() const { return name; }

    virtual ~User() {}
};

class Student : public User
{
    int assignments[MAX_ASSIGNMENTS] = {0};

public:
    Student(string n, string i, string e, string p)
        : User(n, i, e, p) {}

    void submitAssignment(int index)
    {
        if (index >= 0 && index < MAX_ASSIGNMENTS)
        {
            assignments[index] = 1;
            cout << "Assignment " << (index + 1) << " submitted for student: " << name << endl;
        }
        else
        {
            cout << "Invalid assignment index for submission.\n";
        }
    }

    void display() override
    {
        User::display();
        cout << "Assignment Status:\n";
        for (int i = 0; i < MAX_ASSIGNMENTS; ++i)
        {
            cout << "\tAssignment " << (i + 1) << ": "
                 << (assignments[i] ? "Submitted" : "Not Submitted") << endl;
        }
    }
};

class TA : public Student
{
    string projects[MAX_PROJECTS];
    int numProjects = 0;
    Student **studentsAssigned;
    int maxStudents = 10;
    int numStudents = 0;

public:
    TA(string n, string i, string e, string p)
        : Student(n, i, e, p)
    {
        studentsAssigned = new Student *[maxStudents];
    }

    void addProject(const string &p)
    {
        if (numProjects < MAX_PROJECTS)
        {
            projects[numProjects++] = p;
            cout << "Project " << p << " assigned to TA: " << name << endl;
        }
        else
        {
            cout << "TA " << name << " cannot take more projects." << endl;
        }
    }

    void assignStudent(Student *s)
    {
        if (numStudents < maxStudents)
        {
            studentsAssigned[numStudents++] = s;
            cout << s->getName() << " assigned under TA: " << name << endl;
        }
        else
        {
            cout << "TA " << name << " reached student assignment limit." << endl;
        }
    }

    void display() override
    {
        Student::display();
        cout << "TA Projects:" << endl;
        for (int i = 0; i < numProjects; ++i)
        {
            cout << "\t" << (i + 1) << ". " << projects[i] << endl;
        }
        cout << "Assigned Students:" << endl;
        for (int i = 0; i < numStudents; ++i)
        {
            cout << "\t" << (i + 1) << ". " << studentsAssigned[i]->getName() << endl;
        }
    }

    ~TA()
    {
        delete[] studentsAssigned;
    }
};

class Professor : public User
{
    TA **assignedTA;
    int maxTA = 3;
    int numTA = 0;

public:
    Professor(string n, string i, string e, string p)
        : User(n, i, e, p)
    {
        assignedTA = new TA *[maxTA];
    }

    void assignTA(TA *t)
    {
        if (numTA < maxTA)
        {
            assignedTA[numTA++] = t;
            cout << t->getName() << " assigned to Professor: " << name << endl;
        }
        else
        {
            cout << "Professor " << name << " can't supervise more TAs." << endl;
        }
    }

    void display() override
    {
        User::display();
        cout << "Professor's TAs:" << endl;
        for (int i = 0; i < numTA; ++i)
        {
            cout << "\t" << (i + 1) << ". " << assignedTA[i]->getName() << endl;
        }
    }

    ~Professor()
    {
        delete[] assignedTA;
    }
};

void authenticateAndPerformAction(User *user, string action, string password)
{
    if (!user->authenticate(password))
    {
        cout << "Authentication failed!" << endl;
        return;
    }

    if (user->hasPermission(action))
    {
        cout << "Action \"" << action << "\" allowed." << endl;
    }
    else
    {
        cout << "Permission denied for action: \"" << action << "\"" << endl;
    }
}

int main()
{
    // Creating users
    Student s1("Alice", "S001", "alice@student.edu", "pass123");
    Student s2("Bob", "S002", "bob@student.edu", "bob456");
    TA ta1("Carol", "T001", "carol@ta.edu", "taPass");
    Professor prof1("Dr. Smith", "P001", "smith@uni.edu", "profPass");

    // Add permissions
    s1.addPermissions("access library");
    s1.addPermissions("access lab");
    ta1.addPermissions("access lab");
    ta1.addPermissions("grade assignments");
    prof1.addPermissions("access lab");
    prof1.addPermissions("manage projects");

    // Submit assignments
    s1.submitAssignment(0);
    s1.submitAssignment(2);
    s2.submitAssignment(1);

    // TA adds projects and assigns students
    ta1.addProject("AI Research");
    ta1.addProject("Data Mining");
    ta1.assignStudent(&s1);
    ta1.assignStudent(&s2);

    // Professor assigns TA
    prof1.assignTA(&ta1);

    // Authenticate users and perform actions
    authenticateAndPerformAction(&s1, "access lab", "pass123");
    authenticateAndPerformAction(&ta1, "grade assignments", "taPass");
    authenticateAndPerformAction(&prof1, "manage projects", "wrongPass");

    // Displaying info
    cout << "\n=== DISPLAY ALL INFO ===\n";
    s1.display();
    s2.display();
    ta1.display();
    prof1.display();

    return 0;
}

