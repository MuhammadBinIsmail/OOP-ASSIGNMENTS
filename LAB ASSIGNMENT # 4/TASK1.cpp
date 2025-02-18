#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Matrix
{
private:
    int rows, cols;
    double *data;

public:
    Matrix() : rows(0), cols(0), data(nullptr) {}
    Matrix(int r, int c) : rows(r), cols(c)
    {
        data = new double[rows * cols](); 
    }
    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols)
    {
        data = new double[rows * cols];
        copy(other.data, other.data + (rows * cols), data);
    }
    Matrix(Matrix &&other) noexcept : rows(other.rows), cols(other.cols), data(other.data)
    {
        other.rows = 0;
        other.cols = 0;
        other.data = nullptr;
    }
    ~Matrix()
    {
        delete[] data;
    }
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    double &at(int r, int c)
    {
        return data[r * cols + c];
    }
    const double &at(int r, int c) const
    {
        return data[r * cols + c];
    }
    void fill(double value)
    {
        std::fill(data, data + (rows * cols), value);
    }
    Matrix transpose() const
    {
        Matrix transposed(cols, rows);
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                transposed.at(c, r) = at(r, c);
            }
        }
        transposed.print();
        return transposed;
    }
    void print() const
    {
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                cout << at(r, c) << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    Matrix mat(rows, cols);
    cout << "Enter matrix elements: " << endl;
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < cols; ++c)
        {
            double value;
            cin >> value;
            mat.at(r, c) = value;
        }
    }
    cout << "Original Matrix:" << endl;
    mat.print();
    cout << "Transposed Matrix:" << endl;
    Matrix transposed = mat.transpose();
    return 0;
}
