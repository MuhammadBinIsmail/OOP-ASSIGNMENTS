#include <iostream>
#include <thread>   //I used this for pausing the execution.
#include <chrono>   //I used this library for time related utilities.
using namespace std;
class Blend
{
private:
    string selectedFruits;
public:
    void selectFruits()
    {
        cout << "Enter the fruits you want to use for the juice: ";
        getline(cin, selectedFruits);
        cout << "Selecting " << selectedFruits << " for juice..." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Fruits selected!" << endl;
    }
    void blendJuice()
    {
        cout << "Blending " << selectedFruits << " juice..." << endl;
        for (int i = 1; i <= 5; ++i)
        {
            cout << "Blending... " << i << " seconds" << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout << "Blending complete!" << endl;
    }
};
class Grind
{
public:
    void grindJuice()
    {
        cout << "Grinding juice..." << endl;
        this_thread::sleep_for(chrono::seconds(5));
        cout << "Grinding complete!" << endl;
    }
};
class JuiceMaker
{
private:
    Blend blender;
    Grind grinder;
public:
    void makeJuice()
    {
        cout << "Starting juice preparation..." << endl;
        blender.selectFruits();
        blender.blendJuice();
        grinder.grindJuice();
        cout << "Juice is ready to serve!" << endl;
    }
};

int main()
{
    JuiceMaker juiceMaker;
    juiceMaker.makeJuice();
    return 0;
}
