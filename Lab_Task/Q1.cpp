// Q1: Write a C++ program to check whether a given number is prime or not. Allow
// the user to input a number and display whether it's prime or not?

#include<iostream>

using namespace std;

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    for(int i = 2 ; i < num; i++)
    {
        if(num % i == 0)
        {
            cout << "Not a prime number" << endl;
            return 0;
        }
    }
    cout << "Prime number" << endl;
}
