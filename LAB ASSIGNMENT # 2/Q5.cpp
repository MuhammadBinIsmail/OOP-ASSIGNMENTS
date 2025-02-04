#include <iostream>
using namespace std;
struct Data
{
    int id;
    string name;
};
void sort_via_id(Data *entity, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (entity[j].id > entity[j + 1].id)
            {
                swap(entity[j], entity[j + 1]);
            }
        }
    }
}
void sort_via_name(Data *entity, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (entity[j].name[0] > entity[j + 1].name[0])
            {
                swap(entity[j], entity[j + 1]);
            }
        }
    }
}
int main()
{
    int N;
    cout << "Enter the number of structures: ";
    cin >> N;

    Data *entity = new Data[N];

    for (int i = 0; i < N; i++)
    {
        cout << "Enter ID for entity " << (i + 1) << ": ";
        cin >> entity[i].id;
        cout << "Enter name for entity " << (i + 1) << ": ";
        cin >> entity[i].name;
    }
    sort_via_id(entity, N);
    cout << "Sorted via ID: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "ID: " << entity[i].id << ", Name: " << entity[i].name << endl;
    }
    sort_via_name(entity, N);
    cout << "Sorted via the first character of Name in asc order: " << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "ID: " << entity[i].id << ", Name: " << entity[i].name << endl;
    }
    delete[] entity;
    return 0;
}
