#include <iostream>
using namespace std;

class Account
{
protected:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    Account(string num, string h, double bal) : accountNumber(num), accountHolder(h), balance(bal) {}

    string getAccountNumber() const { return accountNumber; }
    string getAccountHolder() const { return accountHolder; }
    double getBalance() const { return balance; }

    void setBalance(double amount) { balance = amount; }

    Account operator+(const Account &a)
    {
        return Account(accountNumber, accountHolder, balance + a.balance);
    }

    Account &operator-=(double amount)
    {
        balance -= amount;
        return *this;
    }

    bool operator>(const Account &a)
    {
        return balance > a.balance;
    }

    friend ostream &operator<<(ostream &out, const Account &a);
};

ostream &operator<<(ostream &out, const Account &a)
{
    out << "Account Number: " << a.getAccountNumber() << " | Holder: " << a.getAccountHolder() << " | Balance: $" << a.getBalance() << endl;
    return out;
}

int main()
{
    Account a1("A-1001", "Shafique Rehman", 5000);
    Account a2("A-1002", "Talha Shahid", 3000);

    // Displaying the inital account details
    cout << "Initial Account Details:" << endl;
    cout << a1;
    cout << a2;

    // Adding Account 1 and Account 2 balances
    Account total = a1 + a2;
    cout << endl << "Total Balance (After Addition): $" << total.getBalance() << endl;

    // Transferring 2000 from Account 1 to Account 2
    a1 -= 2000;
    a2.setBalance(a2.getBalance() + 2000);
    cout << endl << "After Transfer:" << endl;
    cout << a1.getAccountHolder() << "'s New Balance: $" << a1.getBalance() << endl;
    cout << a2.getAccountHolder() << "'s New Balance: $" << a2.getBalance() << endl;

    // Checking which account has a higher balance
    cout << endl << "Comparison:" << endl;
    cout << a1.getAccountHolder() << " has " << ((a1 > a2) ? "more" : "less") << " balance than " << a2.getAccountHolder() << "." << endl;

    // Displaying final account details
    cout << endl << "Final Account Details:" << endl;
    cout << a1;
    cout << a2;

    return 0;
}
