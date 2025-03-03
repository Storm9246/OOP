#include<iostream>
using namespace std;

class LoanHelper
{
    const float interestRate;
    float loanAmount;
    int months;

    public:

    LoanHelper(float iRate, float amount, int m): 
    interestRate(iRate), loanAmount(amount), months(m)
    {
        int ir;
        if(interestRate < 0 || interestRate > 0.5)
        {
            cout << "Interest Rate is out of bound must be inder 0.5" << endl;
            return;
        }
    }

    void calculateLoan()
    {
        loanAmount = (loanAmount/months)* interestRate;
        cout << "You have to pay "<< loanAmount << " every month for"<< months <<"to repay your loan" << endl;
        
    }


};


int main()
{

}
