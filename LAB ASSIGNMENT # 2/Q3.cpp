#include <iostream>
using namespace std;
int *resize_array(int *array, int &current_size, int new_size)
{
    int *new_array = new int[new_size];
    for (int i = 0; i < current_size; i++)
    {
        new_array[i] = array[i];
    }
    delete[] array;
    current_size = new_size;
    return new_array;
}
int main()
{
    int current_size = 5;
    int *array = new int[current_size];
    int element_count = 0;
    cout << "Enter integers or enter a negative number to stop:\n";
    while (true)
    {
        int user_input;
        cin >> user_input;
        if (user_input < 0)
        {
            break;
        }
        if (element_count >= current_size)
        {
            int new_size = 2 * current_size;
            cout << "Resizing array from " << current_size << " to " << new_size << endl;
            array = resize_array(array, current_size, new_size);
        }
        array[element_count] = user_input;
        element_count++;
    }
    if (element_count < current_size)
    {
        cout << "Final array size: " << element_count << endl;
        array = resize_array(array, current_size, element_count);
    }
    cout << "All array elements:\n";
    for (int i = 0; i < element_count; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    delete[] array;
    return 0;
}