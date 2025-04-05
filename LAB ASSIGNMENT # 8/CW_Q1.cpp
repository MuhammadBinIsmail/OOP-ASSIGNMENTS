#include <iostream>
#include <numeric> 
#include <algorithm> 
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;
    void reduce() {
        if (denominator == 0) {
            cout << "Error: Denominator cannot be zero" << endl;
            numerator = 0;
            denominator = 1;
            return;
        }
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        int common_divisor = gcd(abs(numerator), abs(denominator));
        if (common_divisor != 0) {
            numerator /= common_divisor;
            denominator /= common_divisor;
        }
    }
public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        reduce();
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    Fraction operator+(const Fraction& other) const {
        int new_num = numerator * other.denominator + other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }
    Fraction operator-(const Fraction& other) const {
        int new_num = numerator * other.denominator - other.numerator * denominator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }
    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            cout << "Error: Cannot divide by zero" << endl;
            return Fraction(0, 1);
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }
    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }
    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }
    bool operator<=(const Fraction& other) const {
        return *this < other || *this == other;
    }
    bool operator>=(const Fraction& other) const {
        return *this > other || *this == other;
    }
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.denominator == 1) {
            os << f.numerator;
        } else {
            os << f.numerator << "/" << f.denominator;
        }
        return os;
    }
    friend istream& operator>>(istream& is, Fraction& f) {
        int num, denom = 1;
        char slash;
        is >> num;
        if (is.peek() == '/') {
            is >> slash >> denom;
        }
        f = Fraction(num, denom);
        return is;
    }
};

int main() {
    Fraction f1(2, 4);
    Fraction f2(3, 6);
    
    cout << "f1: " << f1 << endl;  
    cout << "f2: " << f2 << endl;  
    
    cout << "f1 + f2: " << (f1 + f2) << endl;  
    cout << "f1 - f2: " << (f1 - f2) << endl;  
    cout << "f1 * f2: " << (f1 * f2) << endl;  
    cout << "f1 / f2: " << (f1 / f2) << endl;  
    
    cout << "f1 == f2: " << (f1 == f2) << endl;  
    cout << "f1 != f2: " << (f1 != f2) << endl;  
    
    Fraction f3(1, 3);
    cout << "\nFraction 3 is: (1 , 3)\n" << endl;
    cout << "f1 < f3: " << (f1 < f3) << endl;  
    cout << "f1 > f3: " << (f1 > f3) << endl;  

    Fraction f4;
    cout << "Enter a fraction (format a/b or a): ";
    cin >> f4;
    cout << "You entered: " << f4 << endl;
    
    cout << "\nTesting error cases:" << endl;
    Fraction f5(1, 0); 
    cout << "f5 (1/0): " << f5 << endl;
    Fraction zero(0, 1);
    Fraction divByZero = f1 / zero;
    cout << "f1 / 0: " << divByZero << endl;
    return 0;
}