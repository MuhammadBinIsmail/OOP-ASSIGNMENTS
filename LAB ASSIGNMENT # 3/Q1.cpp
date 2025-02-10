#include <iostream>
#include <string>
using namespace std;

class User
{
public:
    int Age;
    string Name;
};

int main()
{
    User object;
    object.Name = "Teo";
    object.Age = 24;

    cout << "My name is " << object.Name << " and I am " << object.Age << " years old.";
    return 0;
}
