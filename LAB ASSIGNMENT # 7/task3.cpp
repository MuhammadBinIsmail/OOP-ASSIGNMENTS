#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Currency
{
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRateToUSD;
public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRateToUSD(rate) {}
    double convertToUSD()
    {
        return amount * exchangeRateToUSD;
    }
    double convertFromUSD(double usdAmount)
    {
        return usdAmount / exchangeRateToUSD;
    }
    double convertTo(string targetCode)
    {
        double usdAmount = convertToUSD();
        if (targetCode == "USD")
            return usdAmount;
        if (targetCode == "EUR")
            return usdAmount * 0.95;
        if (targetCode == "GBP")
            return usdAmount * 0.73;
        if (targetCode == "PKR")
            return usdAmount * 280.37;
        return 0;
    }
    void display()
    {
        cout << fixed << setprecision(2);
        cout << currencySymbol << amount << " (" << currencyCode << ")";
    }
};
class Dollar : public Currency
{
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
};
class Euro : public Currency
{
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1 / 0.85) {}
};
class Rupee : public Currency
{
public:
    Rupee(double amt) : Currency(amt, "PKR", "RS", 1 / 74.50) {}
};
int main()
{
    int fromChoice, toChoice;
    double amount;
    cout << "   Currency Converter    \n";
    cout << "1. Dollar (USD)\n2. Euro (EUR)\n3. Rupee (PKR)\n";
    cout << "Convert from (1-3): ";
    cin >> fromChoice;
    cout << "Enter amount: ";
    cin >> amount;
    cout << "Convert to (1-3): ";
    cin >> toChoice;
    Currency *fromCurrency = nullptr;
    string toCode;
    switch (fromChoice)
    {
    case 1:
        fromCurrency = new Dollar(amount);
        break;
    case 2:
        fromCurrency = new Euro(amount);
        break;
    case 3:
        fromCurrency = new Rupee(amount);
        break;
    default:
        cout << "Invalid choice!";
        return 1;
    }
    switch (toChoice)
    {
    case 1:
        toCode = "USD";
        break;
    case 2:
        toCode = "EUR";
        break;
    case 3:
        toCode = "PKR";
        break;
    default:
        cout << "Invalid choice!";
        return 1;
    }
    cout << "\nOriginal: ";
    fromCurrency->display();
    cout << "\nConverted to " << toCode << ": ";
    double converted = fromCurrency->convertTo(toCode);
    if (toCode == "USD")
        cout << "$";
    else if (toCode == "EUR")
        cout << "€";
    else if (toCode == "PKR")
        cout << "RS";
    cout << converted << endl;
    delete fromCurrency;
    return 0;
}