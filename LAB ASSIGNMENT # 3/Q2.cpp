#include <iostream>
using namespace std;
class Date
{
public:
    int month;
    int day;
    int year;

    void displayDate()
    {
        cout << month << "/" << day << "/" << year << endl;
    }
};

int main()
{
    Date object;
    cout << "Enter Day: ";
    cin >> object.day;
    cout << "Enter Month: ";
    cin >> object.month;
    cout << "Enter Year: ";
    cin >> object.year;
    cout << "The date is: ";
    object.displayDate();
    return 0;
}
