#include <iostream>
#include <string>
using namespace std;
class Vehicles
{
protected:
    double vehicle_price;
public:
    Vehicles(double price) : vehicle_price(price) {}
    virtual void displayDetails()
    {
        cout << "The price of the vehicle is: " << vehicle_price << endl;
    }
};
class Car : public Vehicles
{
protected:
    int seating_capacity;
    int no_of_doors;
    string fuel_type;
public:
    Car(double price, int seats, int doors, string fuel) : Vehicles(price), seating_capacity(seats), no_of_doors(doors), fuel_type(fuel) {}
    void displayDetails() override
    {
        Vehicles::displayDetails();
        cout << "Seating Capacity: " << seating_capacity << "  Doors: " << no_of_doors << "  Fuel Type: " << fuel_type << endl;
    }
};
class Motorcycle : public Vehicles
{
protected:
    int no_of_cylinders;
    int no_of_gears;
    int no_of_wheels;

public:
    Motorcycle(double price, int cylinders, int gears, int wheels) : Vehicles(price), no_of_cylinders(cylinders), no_of_gears(gears), no_of_wheels(wheels) {}
    void displayDetails() override
    {
        Vehicles::displayDetails();
        cout << "Cylinders: " << no_of_cylinders << "  Gears: " << no_of_gears << "  Wheels: " << no_of_wheels << endl;
    }
};
class Audi : public Car
{
private:
    string model_type;

public:
    Audi(double price, int seats, int doors, string fuel, string model) : Car(price, seats, doors, fuel), model_type(model) {}
    void displayDetails() override
    {
        cout << "Audi Car Details:\n";
        Car::displayDetails();
        cout << "Model Type: " << model_type << endl;
    }
};
class Yamaha : public Motorcycle
{
private:
    string make_type;
public:
    Yamaha(double price, int cylinders, int gears, int wheels, string make) : Motorcycle(price, cylinders, gears, wheels), make_type(make) {}
    void displayDetails() override
    {
        cout << "Yamaha Motorcycle Details:\n";
        Motorcycle::displayDetails();
        cout << "Make Type: " << make_type << endl;
    }
};
int main()
{
    Audi audiCar(50000, 5, 4, "Petrol", "A4");
    Yamaha yamahaBike(15000, 2, 6, 2, "YZF-R1");
    audiCar.displayDetails();
    yamahaBike.displayDetails();
    return 0;
}
