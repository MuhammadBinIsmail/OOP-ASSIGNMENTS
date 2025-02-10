#include <iostream>
using namespace std;
class Glass
{
public:
    int LiquidLevel;
    Glass()
    {
        LiquidLevel = 200;
    }
    void Drink(int milliliters)
    {
        if (milliliters > LiquidLevel)
        {
            cout << "Not enough liquid to drink." << endl;
            return;
        }
        LiquidLevel = LiquidLevel - milliliters;
        cout << "You drank " << milliliters << " ml. Remaining: " << LiquidLevel << " ml." << endl;
        if (LiquidLevel < 100)
        {
            Refill();
        }
    }
    void Refill()
    {
        LiquidLevel = 200;
        cout << "Glass refilled to 200 ml." << endl;
    }
};
int main()
{
    Glass water;
    int amount;
    cout << "Your glass full at 200 ml." << endl;
    cout << "Enter how much you want to drink or enter 0 to exit." << endl;
    while (true)
    {
        cout << "\nEnter amount to drink in ml: ";
        cin >> amount;
        if (amount == 0)
        {
            cout << "Exiting program." << endl;
            break;
        }
        water.Drink(amount);
    }
    return 0;
}
