#include <iostream>
using namespace std;

class shape {
private:
    double area;
public:
    shape(double a = 0) : area(a) {}
    double Area() const {
        return area;
    }
    void setArea(double a) {
        area = a;
    }  
    shape operator+(const shape& other) {
        return shape(area + other.area);
    }
};
int main() {
    shape shape1(25.5);
    shape shape2(30.75);
    shape total = shape1 + shape2;
    cout << "Area of shape1: " << shape1.Area() << endl;
    cout << "Area of shape2: " << shape2.Area() << endl;
    cout << "Total area: " << total.Area() << endl;
    return 0;
}