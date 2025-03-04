#include <iostream>
#include <vector>

class Car
{
private:
    std::string name;
    int id;
public:
    Car(std::string carName, int carId) : name(carName), id(carId)
    {
        std::cout << "Car constructed: " << name << " (ID: " << id << ")" << std::endl;
    }

    ~Car()
    {
        std::cout << "Car destroyed: " << name << " (ID: " << id << ")" << std::endl;
    }
    std::string getName() const
    {
        return name;
    }
    int getId() const
    {
        return id;
    }
};

class Garage
{
private:
    std::vector<Car *> cars;
public:
    void parkCar(Car *car)
    {
        if (car)
        {
            cars.push_back(car);
            std::cout << "Car parked: " << car->getName() << " (ID: " << car->getId() << ")" << std::endl;
        }
    }
    void listCars() const
    {
        std::cout << "Cars in garage:" << std::endl;
        for (const auto &car : cars)
        {
            std::cout << "- " << car->getName() << " (ID: " << car->getId() << ")" << std::endl;
        }
    }
};

int main()
{
    Garage garage;
    {
        Car car1("Suzuki", 1);
        Car car2("Mercedes", 2);

        garage.parkCar(&car1);
        garage.parkCar(&car2);
        garage.listCars();
    } 
    std::cout << "Attempting to list cars after they are destroyed:" << std::endl;
    garage.listCars(); 
    return 0;
}
