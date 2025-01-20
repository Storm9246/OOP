// Q2: Design a C++ program to manage student marks. Allow the user to input
// marks for students in three subjects (Mathematics, English, and Science). The
// program should calculate the total marks, average marks, and display the grade
// for each student. The user can specify the number of students and then input
// the marks for each subject for each student. Finally, display the marks, total,
// average, and grade for each student. Assume a grading system with the
// following criteria:
// 90 or above: Grade A
// 80-89: Grade B
// 70-79: Grade C
// 60-69: Grade D
// Below 60: Grade F

#include <iostream>

using namespace std;

struct student
{
    float Maths;
    float English;
    float Science;
};

int check(int num);

int main()
{
    int num;
    float average = 0, tmarks;
    
    cout << "Enter the number of students: ";
    cin >> num;
    student* std = new student[num];
    if(!std)
    {
        cout << "Memory error";
        return 1;
    }
    float* total = new float[num];
    if(!total)
    {
        cout << "Memory error";
        return 1;
    }

    for(int i = 0; i < num; i++ )
    {
        cout << "Enter the marks of Maths of " << i+1 << ": ";
        cin >> std[i].Maths;
        if(check(std[i].Maths))
        {
            return 1;
        }

        cout << "Enter the marks of English of " << i+1 << ": ";
        cin >> std[i].English;
        if(check(std[i].English))
        {
            return 1;
        }

        cout << "Enter the marks of Science of " << i+1 << ": ";
        cin >> std[i].Science; 
        if(check(std[i].Science))
        {
            return 1;
        }

        total[i] = std[i].Maths + std[i].English + std[i].Science;
        average += total[i];
    }

    cout << "Average marks are: " << average/num<< endl;
    for(int i = 0; i < num ; i++)
    {
        cout << "student " << i+ 1 << endl;
        cout << "total marks are: " << total[i] << endl;
        tmarks = (total[i] / 300) * 100;
        if(tmarks < 60)
        {
            cout << "Grade F" << endl;
        }
        else if(tmarks < 70)
        {
            cout << "Grade D" << endl;
        }
        else if(tmarks < 80)
        {
            cout << "Grade C" << endl;
        }
        else if(tmarks < 90)
        {
            cout << "Grade B" << endl;
        }
        else
        {
            cout << "Grade A" << endl;
        }

    }

    delete std;
    delete total;
}

int check(int num)
{
    if(num > 100 || num < 0)
    {
        cout << "wrong input must be in between 0 and 100" << endl; 
        return 1;
    }
    return 0;
}