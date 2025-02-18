#include <iostream>
#include <vector>
using namespace std;
class Polynomial
{
private:
    double *coefficients; 
    int degree;           
public:
    Polynomial() : degree(0)
    {
        coefficients = new double[1]{0.0};
    }
    Polynomial(int deg, const double *coeffs) : degree(deg)
    {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++)
        {
            coefficients[i] = coeffs[i];
        }
    }
    Polynomial(const Polynomial &other) : degree(other.degree)
    {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++)
        {
            coefficients[i] = other.coefficients[i];
        }
    }
    Polynomial(Polynomial &&other) noexcept : degree(other.degree), coefficients(other.coefficients)
    {
        other.coefficients = nullptr;
        other.degree = 0;
    }
    ~Polynomial()
    {
        delete[] coefficients;
    }
    int getDegree() const
    {
        return degree;
    }
    double evaluate(double x) const
    {
        double result = 0.0;
        double power = 1.0;
        for (int i = 0; i <= degree; i++)
        {
            result += coefficients[i] * power;
            power *= x;
        }
        return result;
    }
    Polynomial add(const Polynomial &other) const
    {
        int maxDegree = max(degree, other.degree);
        double *resultCoeffs = new double[maxDegree + 1]{};

        for (int i = 0; i <= maxDegree; i++)
        {
            double coeff1 = (i <= degree) ? coefficients[i] : 0.0;
            double coeff2 = (i <= other.degree) ? other.coefficients[i] : 0.0;
            resultCoeffs[i] = coeff1 + coeff2;
        }

        Polynomial result(maxDegree, resultCoeffs);
        delete[] resultCoeffs;
        return result;
    }
    Polynomial multiply(const Polynomial &other) const
    {
        int resultDegree = degree + other.degree;
        double *resultCoeffs = new double[resultDegree + 1]{};

        for (int i = 0; i <= degree; i++)
        {
            for (int j = 0; j <= other.degree; j++)
            {
                resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        Polynomial result(resultDegree, resultCoeffs);
        delete[] resultCoeffs;
        return result;
    }
    void print() const
    {
        for (int i = degree; i >= 0; i--)
        {
            if (coefficients[i] != 0)
            {
                if (i != degree)
                    cout << " + ";
                cout << coefficients[i];
                if (i > 0)
                {
                    cout << "x";
                    if (i > 1)
                        cout << "^" << i;
                }
            }
        }
        cout << endl;
    }
};
int main()
{
    int degree1, degree2;
    cout << "Enter the degree of the first polynomial: ";
    cin >> degree1;
    double *coeffs1 = new double[degree1 + 1];
    cout << "Enter the coefficients for the first polynomial: ";
    for (int i = 0; i <= degree1; i++)
    {
        cin >> coeffs1[i];
    }
    Polynomial p1(degree1, coeffs1);
    delete[] coeffs1;

    cout << "Enter the degree of the second polynomial: ";
    cin >> degree2;
    double *coeffs2 = new double[degree2 + 1];
    cout << "Enter the coefficients for the second polynomial: ";
    for (int i = 0; i <= degree2; i++)
    {
        cin >> coeffs2[i];
    }
    Polynomial p2(degree2, coeffs2);
    delete[] coeffs2;
    cout << "Polynomial 1: ";
    p1.print();
    cout << "Polynomial 2: ";
    p2.print();
    Polynomial sum = p1.add(p2);
    cout << "Sum: ";
    sum.print();
    Polynomial product = p1.multiply(p2);
    cout << "Product: ";
    product.print();
    double x;
    cout << "Enter a value of x to evaluate polynomial 1: ";
    cin >> x;
    cout << "Result: " << p1.evaluate(x) << endl;
    return 0;
}
