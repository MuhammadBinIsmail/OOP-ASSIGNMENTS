#include <iostream>
using namespace std;
class Shape
{
protected:
    string color;
    double x;
    double y;
    double borderThickness;

public:
    Shape(double posx, double posy, string col, double border = 1.0) : x(posx), y(posy), color(col), borderThickness(border) {}
    virtual void draw()
    {
        cout << "Drawing a shape at position " << x << ", " << y << endl;
    }
    virtual double calculateArea()
    {
        return 0;
    }
    virtual double calculatePerimeter()
    {
        return 0;
    }
};
class Circle : public Shape
{
private:
    double radius;
public:
    Circle(double posx, double posy, double r, string col):
    Shape (posx, posy, col), radius(r) {}
    
    void draw() override {
        cout << "Drawaing a circle at " << x << ", " << y << "  with radius " << radius << endl;
    }
    double calculateArea() override { 
        return 3.14159 * radius * radius; 
    }
    double calculatePerimeter() override { 
        return 2 * 3.14159 * radius; 
    }
};
class Rectangle : public Shape
{
private:
    double width;
    double height;
    //double topLeft;
public:
    Rectangle(double posx, double posy, double w, double h, string col)
        : Shape(posx, posy, col), width(w), height(h) {}

    void draw() override
    {
        cout << "Drawing a Rectangle at " << x << ", " << y << "  with dimensions "
             << width << "x" << height << endl;
    }

    double calculateArea() override { 
        return width * height; 
    }
    double calculatePerimeter() override { 
        return 2 * (width + height); 
    }
};

int main()
{
    int shapeChoice;
    double x, y, dim1, dim2;
    string color;
    cout << "=== Shape Creation ===" << endl;
    cout << "1. Circle\n2. Rectangle\nEnter choice: ";
    cin >> shapeChoice;
    cin.ignore();
    cout << "Enter X position: ";
    cin >> x;
    cout << "Enter Y position: ";
    cin >> y;
    cout << "Enter color: ";
    cin >> color;
    if (shapeChoice == 1)
    {
        cout << "Enter radius: ";
        cin >> dim1;
        Circle shape(x, y, dim1, color);
        shape.draw();
        cout << "Area: " << shape.calculateArea() << endl;
        cout << "Perimeter: " << shape.calculatePerimeter() << endl;
    }
    else
    {
        cout << "Enter width: ";
        cin >> dim1;
        cout << "Enter height: ";
        cin >> dim2;
        Rectangle shape(x, y, dim1, dim2, color);
        shape.draw();
        cout << "Area: " << shape.calculateArea() << endl;
        cout << "Perimeter: " << shape.calculatePerimeter() << endl;
    }
    return 0;
}
