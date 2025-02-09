/* Create a class called calendar. The calendar should have 12 arrays for each month of the year, and a variable that
stores information about the current year. The user is allowed to store their tasks to do against each day. Assume
only one entry is needed per day.
Create the following methods for your class:
 --> Add a task. Thisfunction accepts three parameters: task details, date and month. It should add
 --> a task on the day specified.
 --> Remove a task. Accepts the date and month as a parameter to remove the task from.
 --> Show tasks. This method should go through all of your months and print all the tasks allocated.
Your task is to create one calendar object, then hardcode 5-6 tasks for your calendar. Then demonstrate how
you’ll remove a task, and display the updated task list. */

#include <iostream>
using namespace std;

class Calendar
{
    string **months;
    string info;

public:
    Calendar()
    {
        months = new string *[12];
        for (int i = 0; i < 12; i++)
        {
            months[i] = new string[31];
            for (int j = 0; j < 31; j++)
            {
                months[i][j] = "";
            }
        }
    }

    void addTask(int month, int date, string details)
    {
        if (month < 1 || month > 12)
        {
            cout << "Invalid month entered!";
            return;
        }

        if (date < 1 || date > 31)
        {
            cout << "Invalid date entered";
            return;
        }

        months[month - 1][date - 1] = details;
        cout << "Task added successfully." << endl;
    }

    void removeTask(int month, int date)
    {
        if (month < 1 || month > 12)
        {
            cout << "Invalid month entered!";
            return;
        }

        if (date < 1 || date > 31)
        {
            cout << "Invalid date entered";
            return;
        }

        months[month - 1][date - 1] = "";
        cout << "Task removed successfully." << endl;
    }

    void displayTasks()
    {
        int count = 0;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                if (months[i][j] != "")
                {
                    cout << "Task " << ++count << ": " << months[i][j] << " for month " << (i + 1) << " and day " << (j + 1) << "." << endl;
                }
            }
        }
    }
};

int main()
{
    Calendar cal;

    cal.addTask(3, 10, "Washing dishes");
    cal.addTask(5, 24, "Gardening");
    cal.addTask(11, 25, "Taking the dog out for a walk");
    cal.addTask(4, 10, "Cleaning the cellar");
    cal.addTask(9, 17, "Updating the bookshelf");
    cal.addTask(7, 20, "Buy new clothes");

    cal.displayTasks();

    cal.removeTask(11, 25);
    cal.removeTask(4, 10);
    cal.removeTask(9, 17);

    cal.displayTasks();
    return 0;
}