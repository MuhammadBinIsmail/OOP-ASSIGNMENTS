#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

class BigInteger {
private:
    std::vector<int> digits;
    bool isNegative;
    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }
    void addDigits(const std::vector<int>& otherDigits) {
        int carry = 0;
        size_t maxSize = std::max(digits.size(), otherDigits.size());
        
        for (size_t i = 0; i < maxSize || carry; ++i) {
            if (i == digits.size()) {
                digits.push_back(0);
            }
            digits[i] += carry + (i < otherDigits.size() ? otherDigits[i] : 0);
            carry = digits[i] >= 10;
            if (carry) {
                digits[i] -= 10;
            }
        }
    }
    void subtractDigits(const std::vector<int>& otherDigits) {
        int borrow = 0;
        for (size_t i = 0; i < otherDigits.size() || borrow; ++i) {
            digits[i] -= borrow + (i < otherDigits.size() ? otherDigits[i] : 0);
            borrow = digits[i] < 0;
            if (borrow) {
                digits[i] += 10;
            }
        }
        removeLeadingZeros();
    }
    static bool isLessThan(const std::vector<int>& a, const std::vector<int>& b) {
        if (a.size() != b.size()) {
            return a.size() < b.size();
        }
        for (int i = a.size() - 1; i >= 0; --i) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
        return false;
    }
public:
    BigInteger() : digits({0}), isNegative(false) {}
    
    BigInteger(const std::string& numStr) {
        if (numStr.empty()) {
            throw std::invalid_argument("Empty string");
        }
        size_t start = 0;
        if (numStr[0] == '-') {
            isNegative = true;
            start = 1;
        } else {
            isNegative = false;
        }
        for (int i = numStr.length() - 1; i >= static_cast<int>(start); --i) {
            if (!isdigit(numStr[i])) {
                throw std::invalid_argument("Invalid character in number");
            }
            digits.push_back(numStr[i] - '0');
        }
        removeLeadingZeros();
    }
    BigInteger(long long num) : BigInteger(std::to_string(num)) {}
    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            BigInteger result = *this;
            result.addDigits(other.digits);
            return result;
        }
        if (isLessThan(digits, other.digits)) {
            BigInteger result = other;
            result.subtractDigits(digits);
            result.isNegative = other.isNegative;
            return result;
        } else {
            BigInteger result = *this;
            result.subtractDigits(other.digits);
            result.isNegative = isNegative;
            return result;
        }
    }
    BigInteger operator-(const BigInteger& other) const {
        BigInteger negOther = other;
        negOther.isNegative = !negOther.isNegative;
        return *this + negOther;
    }
    BigInteger operator*(const BigInteger& other) const {
        BigInteger result;
        result.digits.resize(digits.size() + other.digits.size(), 0);   
        for (size_t i = 0; i < digits.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < other.digits.size() || carry; ++j) {
                long long current = result.digits[i + j] +
                                  digits[i] * (j < other.digits.size() ? other.digits[j] : 0) +
                                  carry;
                result.digits[i + j] = current % 10;
                carry = current / 10;
            }
        }
        result.isNegative = isNegative != other.isNegative;
        result.removeLeadingZeros();
        return result;
    }
    bool operator==(const BigInteger& other) const {
        return digits == other.digits && isNegative == other.isNegative;
    }
    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }
    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return isNegative;
        }
        if (isNegative) {
            return isLessThan(other.digits, digits);
        }
        return isLessThan(digits, other.digits);
    }
    bool operator>(const BigInteger& other) const {
        return other < *this;
    }
    bool operator<=(const BigInteger& other) const {
        return !(other < *this);
    }
    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }
    friend std::ostream& operator<<(std::ostream& os, const BigInteger& num) {
        if (num.isNegative) {
            os << '-';
        }
        for (int i = num.digits.size() - 1; i >= 0; --i) {
            os << num.digits[i];
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, BigInteger& num) {
        std::string input;
        is >> input;
        num = BigInteger(input);
        return is;
    }
};
int main() {
    BigInteger a("12345678901234567890");
    BigInteger b("98765432109876543210");
    BigInteger c = a + b;
    BigInteger d = b - a;
    BigInteger e = a * b;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << c << std::endl;
    std::cout << "b - a = " << d << std::endl;
    std::cout << "a * b = " << e << std::endl;

    std::cout << "a == b? " << (a == b) << std::endl;
    std::cout << "a < b? " << (a < b) << std::endl;
    std::cout << "a > b? " << (a > b) << std::endl;

    BigInteger f;
    std::cout << "Enter a big integer: ";
    std::cin >> f;
    std::cout << "You entered: " << f << std::endl;
    return 0;
}