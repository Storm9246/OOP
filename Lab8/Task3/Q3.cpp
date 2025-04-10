/* 
No, a friend function must require an object to access non-static private or protected members. It cannot access them directly 
(like static members) because friendship grants access only through instances of the class.

Does it always need an object to access these members?
Yes, if you need to access non-static private or protected members of an object of a class. 

Can a friend function access them directly without an object?
No, unless you need to access static members.

Under what conditions might it fail?
If the member is non-static and the function tries to access it without an object.
*/

#include <iostream>
using namespace std;

class Number{
    int value;
    static int staticMember;

public:
    Number(int v) : value(v) {}

    friend void accessMember(const Number &obj);
    friend void accessStaticMember();
};

void accessMember(const Number &obj){
    cout << "Private data member (Value): " << obj.value << endl;
}

void accessStaticMember(){
    cout << "Static data member: " << Number :: staticMember << endl;
}

int Number :: staticMember = 50;

int main(){
    Number obj(7);
    accessMember(obj);
    accessStaticMember();
    return 0;
}
