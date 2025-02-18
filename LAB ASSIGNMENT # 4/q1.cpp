#include <iostream>
#define PI 3.142

using namespace std;
class Circle
{
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double get_area() const
    {
        return PI * radius * radius;
    }
    double get_perimeter() const
    {
        return 2 * PI * radius;
    }
};

int main()
{
    double r;
    cout << "Enter radius of the circle: ";
    cin >> r;
    Circle circle(r);
    cout << "Area: " << circle.get_area() << endl;
    cout << "Perimeter: " << circle.get_perimeter() << endl;

    return 0;
}
