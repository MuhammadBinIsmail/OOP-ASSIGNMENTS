#include <iostream>
using namespace std;
class Person {
protected:
    string name;
    int empId;
    float salary;
public:
    virtual void getdata() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter employee ID: ";
        cin >> empId;
        cout << "Enter salary: ";
        cin >> salary;
    }
    virtual void displaydata() {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << empId << endl;
        cout << "Salary: " << salary << endl;
    }
    virtual float bonus() = 0;
    virtual ~Person() {} // Added virtual destructor
};
class Admin : virtual public Person {
public:
    float bonus() override {
        return salary * 0.10;
    }
};
class Account : virtual public Person {
public:
    float bonus() override {
        return salary * 0.08;
    }
};
class Master : public Admin, public Account {
public:
    void getdata() override {
        Person::getdata();
    }
    void displaydata() override {
        Person::displaydata();
    }
    float bonus() override {
        return salary * 0.15;
    }
};

int main() {
    Person* employees[3];
    employees[0] = new Admin();
    employees[1] = new Account();
    employees[2] = new Master();
    cout << "Enter Admin employee details:\n";
    employees[0]->getdata();
    cout << "\nEnter Account employee details:\n";
    employees[1]->getdata();
    cout << "\nEnter Master employee details:\n";
    employees[2]->getdata();
    cout << "\nEmployee Details with Bonus:\n";
    for(int i = 0; i < 3; i++) {
        employees[i]->displaydata();
        cout << "Bonus: " << employees[i]->bonus() << endl << endl;
    }
    for(int i = 0; i < 3; i++) {
        delete employees[i];
    }
    return 0;
}