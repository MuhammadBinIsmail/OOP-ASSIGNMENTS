#include <iostream>
using namespace std;
class Account
{
private:
    double balance;
public:
    Account(double initialBalance)
    {
        balance = (initialBalance >= 0) ? initialBalance : 0;
    }
    void credit(double amount)
    {
        if (amount > 0)
        {
            balance =balance + amount;
        }
    }
    void debit(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance = balance - amount;
        }
        else
        {
            cout << "Debit amount exceeded." << endl;
        }
    }
    double get_balance() const
    {
        return balance;
    }
};

int main()
{
    double initialBalance, creditAmount, debitAmount;
    cout << "Enter initial balance: ";
    cin >> initialBalance;
    Account myAccount(initialBalance);
    cout << "Enter amount to credit: ";
    cin >> creditAmount;
    myAccount.credit(creditAmount);
    cout << "Balance after credit: " << myAccount.get_balance() << endl;
    cout << "Enter amount to debit: ";
    cin >> debitAmount;
    myAccount.debit(debitAmount);
    cout << "Balance after debit: " << myAccount.get_balance() << endl;
    return 0;
}
