#include<iostream>
using namespace std;


class Square
{
    private:
        float sideLength;
        float area;
        static float allAreas;

    public:
        Square()
        {
            sideLength = 0.0;
            area = 0.0;
        }
        Square(float sideL)
        {
            sideLength = sideL;
        }

        void setLength(float l)
        {
            sideLength = l;
        }

        void calculateArea()
        {
            area = sideLength * sideLength;
            allAreas += area; 
        }

        float getLength()
        {
            return sideLength;
        }

        float getArea()
        {
            return area;
        }

        float getAllArea()
        {
            return allAreas;
        }




};

float Square::allAreas = 0.0;


int main()
{
    
    Square square1(5.0);  
    Square square2(3.0);  
    Square square3(7.0);  

    square1.calculateArea();
    square2.calculateArea();
    square3.calculateArea();

    cout << "Square 1 - Side Length: " << square1.getLength() << ", Area: " << square1.getArea() << endl;
    cout << "Square 2 - Side Length: " << square2.getLength() << ", Area: " << square2.getArea() << endl;
    cout << "Square 3 - Side Length: " << square3.getLength() << ", Area: " << square3.getArea() << endl;

    cout << "Total area of all squares: " << square1.getAllArea() << endl;

    return 0;
}
