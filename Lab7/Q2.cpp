/* Picture an innovative design tool aimed at architects and graphic designers that allows for creating, manipulating, and analyzing various geometric shapes.
The system is structured around a Shape class, which includes data members such as position, color, and an optional borderThickness. It provides functions like draw() for
rendering, calculateArea() for area measurement, and calculatePerimeter() for perimeter computation.

Derived classes such as Circle, Rectangle, Triangle, and Polygon introduce their own properties--for example, a Circle includes radius and center position, while a Rectangle
includes width, height, and top left corner position. Each derived class overrides draw(), calculateArea(), and calculatePerimeter() to handle their respective geometries. */

#include <iostream>
#include <cmath>
using namespace std;

class Shape{
protected:
    int positionX, positionY;
    string color;
    int borderThickness;

public:
    Shape(int pX, int pY, string c, int bT = 1) : positionX(pX), positionY(pY), color(c), borderThickness(bT) {}
    // Pure virtual functions
    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape{
    int radius;
    int centreX, centreY;

public:
    Circle(int r, int cX, int cY, int pX, int pY, string c, int bT = 1) : radius(r), centreX(cX), centreY(cY), Shape(pX, pY, c, bT) {}

    void draw() override {
        cout << "Drawing a circle at (" << positionX << ", " << positionY << ") at centre: (" << centreX << ", " << centreY << ") with radius: " << radius << ", color: " << color << ", and border thickness: " << borderThickness << endl;
    }

    double calculateArea() override {
        return (3.14159 * radius * radius);
    }

    double calculatePerimeter() override {
        return (2 * 3.14159 * radius);
    }
};

class Rectangle : public Shape{
    int width, height;

public:
    Rectangle(int w, int h, int pX, int pY, string c, int bT = 1) : width(w), height(h), Shape(pX, pY, c, bT) {}

    void draw() override {
        cout << "Drawing a rectangle at (" << positionX << ", " << positionY << ") with width: " << width << ", height: " << height << ", color: " << color << ", and border thickness: " << borderThickness << endl;
    }

    double calculateArea() override {
        return (height * width);
    }

    double calculatePerimeter() override {
        return (2 * (height + width));
    }
};

class Triangle : public Shape{
    int side1, side2, side3;

public:
    Triangle(int s1, int s2, int s3, int pX, int pY, string c, int bT = 1) : side1(s1), side2(s2), side3(s3), Shape(pX, pY, c, bT) {}

    void draw() override {
        cout << "Drawing a triangle at (" << positionX << ", " << positionY << ") with sides: " << side1 << ", " << side2 << ", " << side3 << ", color: " << color << ", and border thickness: " << borderThickness << endl;
    }

    double calculateArea() override {
        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double calculatePerimeter() override {
        return (side1 + side2 + side3);
    }
};

class Polygon : public Shape{
    int sideLength;
    int numSides;

public:
    Polygon(int s, int num, int pX, int pY, string c, int bT = 1) : sideLength(s), numSides(num), Shape(pX, pY, c, bT) {}

    void draw() override {
        cout << "Drawing a regular polygon at (" << positionX << ", " << positionY << ") with " << numSides << " sides of length " << sideLength << ", color: " << color << ", and border thickness: " << borderThickness << endl;
    }

    double calculatePerimeter() override {
        return (numSides * sideLength);
    }

    double calculateArea() override {
        if (numSides < 3) {
            cout << "A polygon must have at least 3 sides." << endl;
            return 0.0;
        }
        return (numSides * sideLength * sideLength) / (4.0 * tan(3.14159 / numSides));
    }
};

int main(){
    Shape *shapes[4];
    shapes[0] = new Circle(5, 10, 10, 3, 3, "red", 2);
    shapes[1] = new Rectangle(10, 5, 2, 2, "blue", 3);
    shapes[2] = new Triangle(3, 4, 5, 1, 1, "green", 1);
    shapes[3] = new Polygon(5, 6, 0, 0, "purple", 2);

    for(int i = 0; i < 4; i++){
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculateArea() << endl;
        cout << "Perimeter: " << shapes[i]->calculatePerimeter() << endl << endl;
    }

    for(int i = 0; i < 4; i++){
        delete shapes[i];
    }
    
    // Circle c(5, 10, 10, 3, 3, "red", 2);
    // c.draw();
    // cout << "Circle Area: " << c.calculateArea() << endl;
    // cout << "Circle Perimeter: " << c.calculatePerimeter() << endl << endl;

    // Rectangle r(10, 5, 2, 2, "blue", 3);
    // r.draw();
    // cout << "Rectangle Area: " << r.calculateArea() << endl;
    // cout << "Rectangle Perimeter: " << r.calculatePerimeter() << endl << endl;

    // Triangle t(3, 4, 5, 1, 1, "green", 1);
    // t.draw();
    // cout << "Triangle Area: " << t.calculateArea() << endl;
    // cout << "Triangle Perimeter: " << t.calculatePerimeter() << endl << endl;

    // Polygon hexagon(5, 6, 0, 0, "purple", 2);
    // hexagon.draw();
    // cout << "Hexagon Area: " << hexagon.calculateArea() << endl;
    // cout << "Hexagon Perimeter: " << hexagon.calculatePerimeter() << endl << endl;
    return 0;
}
