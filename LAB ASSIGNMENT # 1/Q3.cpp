#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
int main()
{
    int customerid, unitsconsumed;
    string customername;
    float amountcharges, surchargeamount = 0, netamount, rate;
    cout << "Enter the Customer ID: ";
    cin >> customerid;
    cout << "Enter the Customer Name: ";
    cin.ignore(); 
    getline(cin, customername);
    cout << "Enter the Units Consumed: ";
    cin >> unitsconsumed;

    if (unitsconsumed <= 199)
    {
        rate = 16.20;
    }
    else if (unitsconsumed >= 200 && unitsconsumed < 300)
    {
        rate = 20.10;
    }
    else if (unitsconsumed >= 300 && unitsconsumed < 500)
    {
        rate = 27.10;
    }
    else
    {
        rate = 35.90;
    }
    amountcharges = unitsconsumed * rate;
    if (amountcharges > 18000)
    {
        surchargeamount = amountcharges * 0.15;
    }
    netamount = amountcharges + surchargeamount;

    
    cout << "\nCustomer ID: " << customerid << endl;
    cout << "Customer Name: " << customername << endl;
    cout << "Units Consumed: " << unitsconsumed << endl;
    cout << "Amount Charges @Rs. " << rate << " per unit: " << amountcharges << endl;
    cout << "Surcharge Amount: " << surchargeamount << endl;
    cout << fixed << setprecision(2);
    cout << "Net Amount Paid by the Customer: " << netamount << endl;
    return 0;
}
