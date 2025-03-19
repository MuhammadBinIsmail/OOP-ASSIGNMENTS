#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount
{
protected:
    string accountNumber;
    double balance;
    bool isFrozen;

public:
    BankAccount(const string &accNum, double bal = 0)
        : accountNumber(accNum), balance(bal), isFrozen(false) {}

    virtual void deposit(double amount)
    {
        if (isFrozen)
        {
            cout << "Account is frozen. Cannot deposit." << endl;
            return;
        }
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited " << amount << ". New balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void withdraw(double amount)
    {
        if (isFrozen)
        {
            cout << "Account is frozen. Cannot withdraw." << endl;
            return;
        }
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew " << amount << ". New balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    void freezeAccount()
    {
        isFrozen = true;
        cout << "Account " << accountNumber << " has been frozen." << endl;
    }

    void unfreezeAccount()
    {
        isFrozen = false;
        cout << "Account " << accountNumber << " has been unfrozen." << endl;
    }

    virtual void display() const
    {
        cout << "Account " << accountNumber << ": Balance = " << balance
             << "  Status: " << (isFrozen ? "Frozen" : "Active") << endl;
    }

    virtual void adjustLimits()
    {
        cout << "No specific limits to adjust for this account type." << endl;
    }

    virtual ~BankAccount() = default;
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(const string &accNum, double bal = 0, double rate = 0.01)
        : BankAccount(accNum, bal), interestRate(rate) {}

    void applyInterest()
    {
        if (isFrozen)
        {
            cout << "Account is frozen. Cannot apply interest." << endl;
            return;
        }
        double interest = balance * interestRate;
        deposit(interest);
        cout << "Interest applied: " << interest << endl;
    }

    void adjustLimits() override
    {
        cout << "Current interest rate: " << interestRate * 100 << "%" << endl;
        cout << "Enter new interest rate (e.g., 1.5 for 1.5%): ";
        double newRate;
        cin >> newRate;
        interestRate = newRate / 100;
        cout << "Interest rate updated to " << interestRate * 100 << "%" << endl;
    }

    void display() const override
    {
        cout << "Savings Account " << accountNumber << ": Balance = " << balance
             << "  Interest Rate: " << interestRate * 100 << "%"
             << "  Status: " << (isFrozen ? "Frozen" : "Active") << endl;
    }
};

class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    CheckingAccount(const string &accNum, double bal = 0, double limit = 100)
        : BankAccount(accNum, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override
    {
        if (isFrozen)
        {
            cout << "Account is frozen. Cannot withdraw." << endl;
            return;
        }
        if (amount > 0 && (balance - amount) >= -overdraftLimit)
        {
            balance -= amount;
            cout << "Withdrew " << amount << ". New balance: " << balance << endl;
            if (balance < 0)
            {
                cout << "ALERT: Overdraft limit reached!" << endl;
            }
        }
        else
        {
            cout << "Invalid withdrawal amount or overdraft limit exceeded." << endl;
        }
    }

    void adjustLimits() override
    {
        cout << "Current overdraft limit: " << overdraftLimit << endl;
        cout << "Enter new overdraft limit: ";
        double newLimit;
        cin >> newLimit;
        overdraftLimit = newLimit;
        cout << "Overdraft limit updated to " << overdraftLimit << endl;
    }

    void display() const override
    {
        cout << "Checking Account " << accountNumber << ": Balance = " << balance
             << "  Overdraft Limit: " << overdraftLimit
             << "  Status: " << (isFrozen ? "Frozen" : "Active") << endl;
    }
};

class BusinessAccount : public BankAccount
{
private:
    double corporateTaxRate;

public:
    BusinessAccount(const string &accNum, double bal = 0, double taxRate = 0.1)
        : BankAccount(accNum, bal), corporateTaxRate(taxRate) {}

    void deposit(double amount) override
    {
        if (isFrozen)
        {
            cout << "Account is frozen. Cannot deposit." << endl;
            return;
        }
        double tax = amount * corporateTaxRate;
        double netAmount = amount - tax;
        balance += netAmount;
        cout << "Deposited " << amount << " (after " << tax << " corporate tax). New balance: " << balance << endl;
    }

    void adjustLimits() override
    {
        cout << "Current corporate tax rate: " << corporateTaxRate * 100 << "%" << endl;
        cout << "Enter new corporate tax rate (e.g., 15 for 15%): ";
        double newRate;
        cin >> newRate;
        corporateTaxRate = newRate / 100;
        cout << "Corporate tax rate updated to " << corporateTaxRate * 100 << "%" << endl;
    }

    void display() const override
    {
        cout << "Business Account " << accountNumber << ": Balance = " << balance
             << "  Corporate Tax Rate: " << corporateTaxRate * 100 << "%"
             << "  Status: " << (isFrozen ? "Frozen" : "Active") << endl;
    }
};

class UserRole
{
public:
    virtual void performAction(BankAccount *account) = 0;
    virtual ~UserRole() = default;
};

class Customer : public UserRole
{
public:
    void performAction(BankAccount *account) override
    {
        cout << "Customer performing actions:" << endl;
        account->deposit(100);
        account->withdraw(50);
    }
};

class Teller : public UserRole
{
public:
    void performAction(BankAccount *account) override
    {
        cout << "Teller performing actions:" << endl;
        account->deposit(200);
        account->withdraw(100);
        account->freezeAccount();
    }
};

class Manager : public UserRole
{
public:
    void performAction(BankAccount *account) override
    {
        cout << "Manager performing actions:" << endl;
        account->deposit(500);
        account->withdraw(300);
        account->unfreezeAccount();
        account->adjustLimits();
    }
};

int main()
{
    SavingsAccount savings("SA123", 1000);
    CheckingAccount checking("CA456", 500, 200);
    BusinessAccount business("BA789", 2000);

    Customer customer;
    Teller teller;
    Manager manager;

    vector<BankAccount *> accounts = {&savings, &checking, &business};

    for (auto account : accounts)
    {
        account->display();
        customer.performAction(account);
        teller.performAction(account);
        manager.performAction(account);
        account->display();
        cout << "-----------------------------" << endl;
    }

    savings.applyInterest();
    savings.display();

    return 0;
}