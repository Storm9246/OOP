/* 
Yes, the friend function can overload the += operator as it has access to the private and protected members of an object of a class and directly modify the left-hand operand if it is passed by a non-constant reference. 
Implementation:
1. First, declare the friend function inside the class.
2. Define the function to accept the left-hand operand as a non-constant reference of an object (to modify) and the right-hand operand as a constant reference of an object (to avoid unnecessary copies).
3. Modify the left-hand operand directly without any getters or setters, as it is a friend function.
4. Return the left-hand operand.
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

    friend Number& operator += (Number &lhs, const Number &rhs);
};

Number& operator += (Number &lhs, const Number &rhs){
    lhs.value += rhs.value;
    return lhs;
}

int main(){
    Number obj1(5), obj2(10);
    obj1.display();
    obj2.display();
    
    obj1 += obj2;

    obj1.display();
    obj2.display();
    return 0;
}
