/*
Yes, a friend function can be used in this scenario. It is particularly useful when a primitive type appears on the right-hand side, such as object + int. 
However, if the primitive type is on the left-hand side, like int + object, the friend function must be implemented accordingly to manage that specific order.
*/

#include <iostream>
using namespace std;

class Number{
    int value;

public:
    Number(int v) : value(v) {}
    void display() const { 
        cout << "Number: " << value << endl; 
    }

    friend Number operator + (const Number &lhs, int rhs);
    friend Number operator + (int lhs, const Number &rhs);
};

Number operator + (const Number &lhs, int rhs){
    return Number(lhs.value + rhs);
}

Number operator + (int lhs, const Number &rhs){
    return Number(lhs + rhs.value);
}

int main(){
    Number obj1(10);
    Number obj2 = obj1 + 30;
    Number obj3 = 15 + obj1;

    obj1.display();
    obj2.display();
    obj3.display();
    return 0;
}
