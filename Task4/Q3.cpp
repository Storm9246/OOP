// TASK # 03
// You are building a bank account management system. Create a class `Account` to manage bank
// accounts.
// Requirements:
// 1. Attributes:
//  `accountNumber` (string)
//  `accountHolderName` (string)
//  `balance` (double)
// 2. Define a default constructor that initializes `balance` to `0.0`.
// 3. Define a parameterized constructor to initialize all attributes.
// 4. Add methods:
//  `deposit(double amount)`: Adds the amount to the balance.
//  `withdraw(double amount)`: Deducts the amount from the balance (if sufficient funds are
// available).
//  `checkBalance()`: Displays the current balance.
// 5. Create a few `Account` objects and test the methods.

#include <iostream>

using namespace std;

class Account
{
    private:
        string accountNumber;
        string accountHolderName;
        double balance;

    public:
        Account()
        {
            balance =  0.0;
        }
        Account(string accountNumber, string accountHolderName, double balance)
        {
            this->accountNumber = accountNumber;
            this->accountHolderName = accountHolderName;
            this->balance = balance;
        }

        void deposit(double amount)
        {   
            balance += amount;
            cout << "deposited" << endl;
        }

        void withdraw(double amount)
        {
            if(balance >= amount)
            {
                balance -= amount;
                cout << "withdrawn" << endl;
            }
            else
            {
                cout << "Insufficient balance" << endl;
            }
        }

        void checkBalance()
        {
            cout << "your balance is: " << balance << endl; 
        }


};

int main()
{
    Account a1("FATU420", "khursheed", 50);

    a1.deposit(59);
    a1.checkBalance();
    a1.withdraw(30);
    a1.checkBalance();
    a1.withdraw(500);
    a1.checkBalance();

}