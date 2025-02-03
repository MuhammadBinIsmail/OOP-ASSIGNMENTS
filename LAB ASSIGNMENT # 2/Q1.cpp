#include <iostream>
#include <cstdlib>
using namespace std;
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Provide atleast one argument.";
        return 1;
    }
    int size = argc - 1;
    int array[size];
    int *ptr = array;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        array[i] = atoi(argv[i + 1]);
    }
    for (int i = 0; i < size; i++)
    {
        sum += *(ptr + i);
    }
    cout << "Sum of all elements in array: " << sum << endl;
    return 0;
}
/*
int main()
{
    int array[3] = {3, 5, 7};
    int *ptr = array;
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += *(ptr + i);
    }
    cout << sum;

    return 0;
}*/