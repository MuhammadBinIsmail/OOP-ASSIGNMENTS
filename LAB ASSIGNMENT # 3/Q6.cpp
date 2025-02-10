#include <iostream>
#include <vector>
using namespace std;
class Matrix
{
private:
    int rows;
    int cols;
    vector<vector<int>> data;

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        data.resize(rows, vector<int>(cols, 0)); 
    }
    int get_rows() const
    {
        return rows;
    }
    int get_cols() const
    {
        return cols;
    }
    void set_element(int i, int j, int value)
    {
        data[i][j] = value; 
    }
    int get_element(int i, int j) const
    {
        return data[i][j]; 
    }
    Matrix add(const Matrix &other) const
    {
        if (rows != other.get_rows() || cols != other.get_cols())
        {
            throw "Matrices cannot be added";
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.set_element(i, j, data[i][j] + other.get_element(i, j));
            }
        }
        return result;
    }
    Matrix multiply(const Matrix &other) const
    {
        if (cols != other.get_rows())
        {
            throw "Matrices cannot be multiplied";
        }
        Matrix result(rows, other.get_cols());
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < other.get_cols(); ++j)
            {
                int sum = 0;
                for (int k = 0; k < cols; ++k)
                {
                    sum = sum + (data[i][k] * other.get_element(k, j));
                }
                result.set_element(i, j, sum);
            }
        }
        return result;
    }
    void display() const
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};
Matrix inputMatrix(int rows, int cols)
{
    Matrix mat(rows, cols);
    cout << "Enter the elements of the matrix (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int value;
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> value;
            mat.set_element(i, j, value);
        }
    }
    return mat;
}
int main()
{
    int rows1, cols1, rows2, cols2;
    cout << "Enter the number of rows for Matrix 1: ";
    cin >> rows1;
    cout << "Enter the number of columns for Matrix 1: ";
    cin >> cols1;
    cout << "Enter the number of rows for Matrix 2: ";
    cin >> rows2;
    cout << "Enter the number of columns for Matrix 2: ";
    cin >> cols2;
    Matrix mat1 = inputMatrix(rows1, cols1);
    Matrix mat2 = inputMatrix(rows2, cols2);
    cout << "Matrix 1:" << endl;
    mat1.display();
    cout << "Matrix 2:" << endl;
    mat2.display();
    try
    {
        Matrix mat3 = mat1.add(mat2);
        cout << "Matrix 1 + Matrix 2:" << endl;
        mat3.display();
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
    try
    {
        Matrix mat4 = mat1.multiply(mat2);
        cout << "Matrix 1 * Matrix 2:" << endl;
        mat4.display();
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
    return 0;
}