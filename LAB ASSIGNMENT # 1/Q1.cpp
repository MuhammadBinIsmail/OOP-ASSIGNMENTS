//Write a program that finds the second highest number in a float type array of 20
//elements using pointer.

#include <iostream>
using namespace std;

int main()
{
    int arraysize;
    cout << "Enter the size of the array: ";
    cin >> arraysize;

    float array[arraysize];
    cout << "Enter " << arraysize << " float type numbers: ";

    for (int i = 0; i < arraysize; i++)
    {
        cin >> *(array + i); 
    }
    for (int i = 0; i < arraysize - 1; i++)
    {
        for (int j = 0; j < arraysize - i - 1; j++)
        {
            if (*(array + j) > *(array + j + 1))
            {
                float swap = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = swap;
            }
        }
    }
    float highest = *(array + arraysize - 1); 
    float sechighest = -1;           
    for (int i = arraysize - 2; i >= 0; i--)
    { 
        if (*(array + i) < highest)
        {
            sechighest = *(array + i); 
            break;
        }
    }
    cout << "Second highest number in the array is: " << sechighest << endl;
    return 0;
}