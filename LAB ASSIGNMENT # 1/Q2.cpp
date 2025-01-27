// Write a program that calculates the sum of all the elements in array using pointers.

#include <iostream>
using namespace std;

int main()
{
    int arraysize;
    cout << "Enter the size of the array: ";
    cin >> arraysize;
    float array[arraysize];
    cout << "Enter " << arraysize << " elements of the array: ";
    for (int i = 0; i < arraysize; i++)
    {
        cin >> *(array + i); 
    }
    float totalsum = 0;
    float *ptr = array; 
    for (int i = 0; i < arraysize; i++)
    {
        totalsum += *(ptr + i); 
    }
    cout << "Sum of all the elements in array is: " << totalsum << endl;
    return 0;
}
