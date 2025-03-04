#include <iostream>
using namespace std;
class Car
{
private:
    int engine_horsepower;
    int seating_capacity;
    int no_of_speakers;
public:
    Car(int hp, int seats, int speakers) : engine_horsepower(hp), seating_capacity(seats), no_of_speakers(speakers) {}
    void displayCarDetails() const
    {
        cout << "Engine Horsepower: " << engine_horsepower << endl;
        cout << "Seating Capacity: " << seating_capacity << endl;
        cout << "Number of Speakers: " << no_of_speakers << endl;
    }
    void modifyAttributes(int hp, int seats, int speakers) const
    {
        Car *nonConstThis = const_cast<Car *>(this);
        nonConstThis->engine_horsepower = hp;
        nonConstThis->seating_capacity = seats;
        nonConstThis->no_of_speakers = speakers;
    }
};

int main()
{
    Car myCar(200, 5, 6);
    cout << "Values of attributes before change:" << endl;
    myCar.displayCarDetails();
    myCar.modifyAttributes(250, 7, 8);
    cout << "Values of attributes after change:" << endl;
    myCar.displayCarDetails();

    return 0;
}
