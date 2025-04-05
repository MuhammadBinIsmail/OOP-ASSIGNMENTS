#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
class PolynomialUtils;
class Polynomial {
private:
    vector<int> coefficients;
    
    void trimZeros() {
        while (!coefficients.empty() && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }
public:
    Polynomial() = default;
    Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {
        trimZeros();
    }
    const vector<int>& getCoefficients() const { return coefficients; }
    Polynomial operator+(const Polynomial& other) const {
        vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result[i] += coefficients[i];
        }
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] += other.coefficients[i];
        }
        return Polynomial(result);
    }
    Polynomial operator-(const Polynomial& other) const {
        vector<int> result(max(coefficients.size(), other.coefficients.size()), 0);   
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result[i] += coefficients[i];
        }
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] -= other.coefficients[i];
        }
        return Polynomial(result);
    }
    Polynomial operator*(const Polynomial& other) const {
        vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);   
        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(result);
    }
    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        if (p.coefficients.empty()) {
            os << "0";
            return os;
        }
        bool firstTerm = true;    
        for (int i = p.coefficients.size() - 1; i >= 0; --i) {
            const int coeff = p.coefficients[i];
            if (coeff == 0) continue;
            if (!firstTerm) {
                if (coeff > 0) {
                    os << " + ";
                } else {
                    os << " - ";
                }
            } else if (coeff < 0) {
                os << "-";
            }
            const int absCoeff = abs(coeff);
            if (absCoeff != 1 || i == 0) {
                if (!firstTerm || coeff < 0) {
                    os << absCoeff;
                } else {
                    os << absCoeff;
                }
            }
            if (i > 0) {
                os << "x";
                if (i > 1) {
                    os << "^" << i;
                }
            }
            firstTerm = false;
        }
        return os;
    }
    friend class PolynomialUtils;
};
class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x) {
        int result = 0;
        for (size_t i = 0; i < p.coefficients.size(); ++i) {
            result += p.coefficients[i] * static_cast<int>(pow(x, i));
        }
        return result;
    }
    static Polynomial derivative(const Polynomial& p) {
        if (p.coefficients.empty()) return Polynomial();
        
        vector<int> derivCoeffs;
        for (size_t i = 1; i < p.coefficients.size(); ++i) {
            derivCoeffs.push_back(p.coefficients[i] * i);
        }
        return Polynomial(derivCoeffs);
    }
};

int main() {
    Polynomial p1({1, 2, 3}); 
    Polynomial p2({-1, 0, 4}); 
    
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    
    cout << "p1 + p2: " << (p1 + p2) << endl;
    cout << "p1 - p2: " << (p1 - p2) << endl;
    cout << "p1 * p2: " << (p1 * p2) << endl;
    
    cout << "Evaluation of p1 at x=2: " << PolynomialUtils::evaluate(p1, 2) << endl;
    cout << "Derivative of p1: " << PolynomialUtils::derivative(p1) << endl;
    
    Polynomial p3({0, 0, 0, 5, -3, 0, 2}); 
    cout << "p3: " << p3 << endl;
    cout << "Derivative of p3: " << PolynomialUtils::derivative(p3) << endl;

    return 0;
}