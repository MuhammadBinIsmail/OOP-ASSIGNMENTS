#include <iostream>
#include <string>
using namespace std;
class Person{
    protected:
    int EmployeeID;
    public:
    void getData(){
        cout << "Enter the Employee ID : " ;
        cin >> EmployeeID;  
    }
    void displayData(){
        cout << "Employee ID :  " <<  EmployeeID << endl;
    }
};
class Admin : public Person{
    private:
    string employeeName;
    double monthlyIncome;
    public:
    void getData(){
        Person :: getData();
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, employeeName);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }
    double bonus(){
        return monthlyIncome * 12 * 0.05;
    }
    void displayData(){
        Person :: displayData();
        cout << "Employee Name :  " << employeeName << endl;
        cout << "Monthly Income :  " << monthlyIncome << endl;
        cout << "Bonus :  " << bonus() << endl;
    }
};
class Accounts : public Person{
    private:
    string employeeName;
    double monthlyIncome;
    public:
    void getData(){
        Person :: getData();
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, employeeName);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }
    double bonus(){
        return monthlyIncome * 12 * 0.05;
    }
    void displayData(){
        Person :: displayData();
        cout << "Employee Name :  " << employeeName << endl;
        cout << "Monthly Income :  " << monthlyIncome << endl;
        cout << "Bonus :  " << bonus() << endl;
    }
};
int main(){
    Admin admin;
    Accounts accounts;
    cout << "Enter Admin Employee Details: \n";
    admin.getData();
    cout << "Enter Accounts Employee Details: \n";
    accounts.getData();
    cout << "\nEmployee Information: \n";
    cout << "Admin Employee: \n";
    admin.displayData();
    cout << "Accounts Employee: \n";
    accounts.displayData();
    return 0;
}