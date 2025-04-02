#include <iostream>
using namespace std;
const int MAX_TRANSACTIONS = 50;
class Account{
protected:
    string accountNumber;
    string accountHolderName;
    double balance;
    string accountType;
    string transactionHistory[MAX_TRANSACTIONS];
    int transactionCount;
public:
    Account(string num, string name, double bal, string type) 
    : accountNumber(num), accountHolderName(name), balance(bal), accountType(type), transactionCount(0){}
    virtual void deposit(double amount){
        balance = balance + amount;
        transactionHistory[transactionCount] = "Deposit: " + std::to_string(amount);
        transactionCount++;
    }
    virtual bool withdraw(double amount){
        if (amount > balance){
            cout << "Insufficient Balance." << endl;
            return false;
        }
        balance = balance - amount;
        transactionHistory[transactionCount] = "Withdrawal: " + std::to_string(amount);
        transactionCount++;
        return true;
    }
    virtual double calculateInterest(){
        return 0;
    }
    virtual void printStatement(){
        cout << "\n  Account Statement  " << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
        cout << "Transaction History:" << endl;
        for (int i = 0; i < transactionCount; i++)
        {
            cout << transactionHistory[i] << endl;
        }
        //cout << "The amount deposited is : " << amount << endl;
        //cout << "The amount withdrawn is : " << amount << endl;
    } 
    virtual void getAccountInfo(){
        cout << "Account Holder Name : " << accountHolderName << endl;
        cout << "Account Type : " << accountType << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Your current balance is : " << balance << endl;
    }
};
class SavingsAccount : public Account
{
private:
    double interestRate;
    double minimumBalance;
public:
    SavingsAccount(string num, string name, double bal, double rate, double minBal)
        : Account(num, name, bal, "Savings"), interestRate(rate), minimumBalance(minBal) {}
    bool withdraw(double amount) override
    {
        if (balance - amount < minimumBalance)
        {
            cout << "Cannot withdraw below minimum balance!" << endl;
            return false;
        }
        return Account::withdraw(amount);
    }
    double calculateInterest() override
    {
        return balance * (interestRate / 100);
    }
};
class FixedDepositAccount : public Account
{
private:
    string maturityDate;
    double fixedInterestRate;
public:
    FixedDepositAccount(string num, string name, double bal, string date, double rate)
        : Account(num, name, bal, "Fixed Deposit"), maturityDate(date), fixedInterestRate(rate) {}
    bool withdraw(double amount) override
    {
        cout << "Cannot withdraw before maturity date: " << maturityDate << endl;
        return false;
    }
    double calculateInterest() override
    {
        return balance * (fixedInterestRate / 100);
    }
};
int main()
{
    SavingsAccount savings("SA123", "MS DHONI", 5000, 3.5, 1000);
    FixedDepositAccount fd("FD456", "VIRAT KOHLI", 10000, "2025-12-31", 5.0);
    savings.deposit(2000);
    savings.withdraw(3000);
    cout << "Interest Earned: " << savings.calculateInterest() << endl;
    savings.printStatement();
    fd.deposit(5000);
    fd.withdraw(2000);
    cout << "Interest Earned: " << fd.calculateInterest() << endl;
    fd.printStatement();
    return 0;
}