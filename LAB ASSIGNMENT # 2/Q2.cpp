#include <iostream>
#include <cstdlib>
using namespace std;
void *add_operations(void *array, void *size)
{
    int *arr = static_cast<int *>(array);
    int n = *static_cast<int *>(size);
    for (int i = 0; i < n; i++)
    {
        arr[i] += 7;
    }
    return static_cast<void *>(arr);
}
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Provide atleast one argument.";
        return 1;
    }
    int size = argc - 1;
    int *array = new int[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = atoi(argv[i + 1]);
    }
    cout << "Original input array: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    void *array_operations = add_operations(static_cast<void *>(array), static_cast<void *>(&size));
    int *final_array = static_cast<int *>(array_operations);
    cout << "Array after add operation: ";
    for (int i = 0; i < size; i++)
    {
        cout << final_array[i] << " ";
    }
    cout << endl;
    delete[] array;
    return 0;
}