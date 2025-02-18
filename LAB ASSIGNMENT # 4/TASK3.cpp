#include <iostream>
using namespace std;
class DynamicArray
{
private:
    int *data;
    int length;

public:
    DynamicArray() : data(nullptr), length(0) {}
    DynamicArray(int size) : length(size)
    {
        data = new int[length]{};
    }
    DynamicArray(const DynamicArray &other) : length(other.length)
    {
        data = new int[length];
        for (int i = 0; i < length; i++)
        {
            data[i] = other.data[i];
        }
    }
    DynamicArray(DynamicArray &&other) noexcept : data(other.data), length(other.length)
    {
        other.data = nullptr;
        other.length = 0;
    }
    DynamicArray &operator=(const DynamicArray &other)
    {
        if (this != &other)
        {
            delete[] data;
            length = other.length;
            data = new int[length];
            for (int i = 0; i < length; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    DynamicArray &operator=(DynamicArray &&other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            length = other.length;
            other.data = nullptr;
            other.length = 0;
        }
        return *this;
    }
    ~DynamicArray()
    {
        delete[] data;
    }
    int size() const
    {
        return length;
    }
    int &at(int index)
    {
        if (index < 0 || index >= length)
        {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }
    void resize(int newSize)
    {
        int *newData = new int[newSize]{};
        int minSize = (newSize < length) ? newSize : length;
        for (int i = 0; i < minSize; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        length = newSize;
    }
    void display() const
    {
        for (int i = 0; i < length; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    int size;
    cout << "Enter the size of the dynamic array: ";
    cin >> size;

    DynamicArray arr(size);
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr.at(i);
    }
    cout << "Array contents: ";
    arr.display();
    int newSize;
    cout << "Enter new size for the array: ";
    cin >> newSize;
    arr.resize(newSize);
    cout << "Resized array contents: ";
    arr.display();
    return 0;
}
