#include <iostream>
using namespace std;

class Engine
{
    private:
    bool isRunning;
    public:
    Engine() : isRunning(false) 
    {
        cout << "Engine constructed." << endl;
    } 
    ~Engine()
    {
        cout << "Engine destroyed." << endl;
    }
    void start()
    {
        if (!isRunning)
        {
            isRunning = true;
            cout << "Engine Started." << endl;
        }
        else
        {
            cout << "Engine is already running." << endl;
        }
    }
    void stop()
    {
        if (isRunning)
        {
            isRunning = false;
            cout << "Engine Stopped." << endl;
        }
        else
        {
            cout << "Engine is already stopped." << endl;
        }
    }
};

class Car
{
    private:
    Engine engine;
    public:
    Car()
    {
        cout << "Car constructed." << endl;
    }
    ~Car() 
    {
        cout << "Car destroyed." << endl;
    }
    void startCar()
    {
        engine.start();
    }
    void stopCar()
    {
        engine.stop();
    }
};

int main()
{
    {
        Car obj;
        obj.startCar();
        obj.stopCar();
    }
    return 0;
}