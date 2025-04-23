#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    double price;
public:
    Car(string m, double p) : model(m), price(p) {}
    string getModel() { 
        return model; 
    }
    double getPrice() { 
        return price; 
    }
    void setModel(string m) { 
        model = m; 
    }
    virtual void setPrice(double p) = 0;
};
class Color : public Car {
private:
    string color;
public:
    Color(string m, double p, string c) : Car(m, p), color(c) {}
    void setPrice(double p) override { 
        price = p; 
    }
    string getColor() { 
        return color; 
    }
    void setColor(string c) { 
        color = c; 
    }
};
class Company : public Car {
private:
    string company;
public:
    Company(string m, double p, string c) : Car(m, p), company(c) {}
    void setPrice(double p) override { 
        price = p; 
    }
    string getCompany() { 
        return company; 
    }
    void setCompany(string c) { 
        company = c; 
    }
};
int main() {
    Color colorCar("Sedan", 25000, "Red");
    Company companyCar("SUV", 35000, "Toyota");
    cout << "Color Car - Model: " << colorCar.getModel() 
         << ", Price: " << colorCar.getPrice() 
         << ", Color: " << colorCar.getColor() << endl;

    cout << "Company Car - Model: " << companyCar.getModel() 
         << ", Price: " << companyCar.getPrice() 
         << ", Company: " << companyCar.getCompany() << endl;

    colorCar.setPrice(27000);
    companyCar.setPrice(38000);
    cout << "\nAfter price update:" << endl;
    cout << "Color Car - New Price: " << colorCar.getPrice() << endl;
    cout << "Company Car - New Price: " << companyCar.getPrice() << endl;
    return 0;
}