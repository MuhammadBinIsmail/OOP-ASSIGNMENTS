#include <iostream>
#include <string>
using namespace std;
class Wallet {
private:
    double balance;
    double dailyDeposits;
    double dailyWithdrawals;
    int currentDay;
    const double MAX_DAILY_DEPOSIT = 10000.0;
    const double MAX_DAILY_WITHDRAWAL = 5000.0;
    void checkDayChange() {
        if (currentDay != appDayCounter) {
            dailyDeposits = 0.0;
            dailyWithdrawals = 0.0;
            currentDay = appDayCounter;
        }
    }
public:
    static int appDayCounter;
    Wallet() : balance(0.0), dailyDeposits(0.0), dailyWithdrawals(0.0), currentDay(0) {
        currentDay = appDayCounter;
    }
    bool deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive." << endl;
            return false;
        }
        checkDayChange();
        if (dailyDeposits + amount > MAX_DAILY_DEPOSIT) {
            cout << "Deposit would exceed daily limit. Remaining capacity: " 
                 << MAX_DAILY_DEPOSIT - dailyDeposits << endl;
            return false;
        }
        balance += amount;
        dailyDeposits += amount;
        return true;
    }
    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive." << endl;
            return false;
        }
        if (amount > balance) {
            cout << "Insufficient funds. Current balance: " << balance << endl;
            return false;
        }
        checkDayChange();
        if (dailyWithdrawals + amount > MAX_DAILY_WITHDRAWAL) {
            cout << "Withdrawal would exceed daily limit. Remaining capacity: " 
                 << MAX_DAILY_WITHDRAWAL - dailyWithdrawals << endl;
            return false;
        }
        balance -= amount;
        dailyWithdrawals += amount;
        return true;
    }
    double getBalance() const {
        return balance;
    }
    friend class User;
};
int Wallet::appDayCounter = 0;

class User {
private:
    string userId;
    string name;
    Wallet wallet;
public:
    User(const string& id, const string& userName) : userId(id), name(userName) {}
    bool deposit(double amount) {
        bool success = wallet.deposit(amount);
        if (success) cout << name << " deposited " << amount << endl;
        return success;
    }
    bool withdraw(double amount) {
        bool success = wallet.withdraw(amount);
        if (success) cout << name << " withdrew " << amount << endl;
        return success;
    }
    void printBalance() const {
        cout << name << "'s balance: " << wallet.getBalance() << endl;
    }
};
void advanceDay() {
    Wallet::appDayCounter++;
    cout << "\nDay advanced to " << Wallet::appDayCounter << "\n" << endl;
}
int main() {
    User ahmed("A123", "Ahmed");
    User usman("B456", "Usman");
    cout << "=== Day 1 ===" << endl;
    ahmed.deposit(500.0);
    ahmed.deposit(1500.0);
    usman.deposit(2000.0);
    ahmed.withdraw(300.0);
    if (!usman.withdraw(2500.0)) cout << "Usman: Withdrawal failed (insufficient funds)" << endl;
    ahmed.printBalance();
    usman.printBalance();
    advanceDay();

    cout << "=== Day 2 ===" << endl;
    ahmed.deposit(1000.0);
    usman.deposit(5000.0);
    ahmed.withdraw(4500.0);
    if (!ahmed.withdraw(5001.0)) cout << "Ahmed: Cannot withdraw (exceeds daily limit)" << endl;
    ahmed.printBalance();
    usman.printBalance();
    advanceDay();
    cout << "=== Day 3 ===" << endl;
    if (!ahmed.deposit(-100.0)) cout << "Ahmed: Cannot deposit negative amount" << endl;
    if (!usman.withdraw(0.0)) cout << "Usman: Cannot withdraw zero amount" << endl;
    ahmed.printBalance();
    usman.printBalance();
    return 0;
}