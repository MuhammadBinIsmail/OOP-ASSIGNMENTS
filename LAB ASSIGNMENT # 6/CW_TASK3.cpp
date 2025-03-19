#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Employee{
protected:
    int id;
    string name;
public:
    Employee(int id, const string &name) : id(id), name(name) {}
    virtual void displayInfo() const{
        cout << "ID: " << id << ", Name: " << name << endl;
    }
    virtual ~Employee() = default;
};
class IOrderTaker{
public:
    virtual void takeOrder() = 0;
    virtual ~IOrderTaker() = default;
};
class IOrderPreparer{
public:
    virtual void prepareOrder() = 0;
    virtual ~IOrderPreparer() = default;
};
class IBiller{
public:
    virtual void generateBill() = 0;
    virtual ~IBiller() = default;
};
class Waiter : public Employee, public IOrderTaker{
public:
    Waiter(int id, const string &name) : Employee(id, name) {}
    void takeOrder() override{
        cout << "Waiter " << name << " is taking the order." << endl;
    }
    void displayInfo() const override{
        cout << "Waiter - ";
        Employee::displayInfo();
    }
};
class Chef : public Employee, public IOrderPreparer{
public:
    Chef(int id, const string &name) : Employee(id, name) {}
    void prepareOrder() override{
        cout << "Chef " << name << " is preparing the order." << endl;
    }
    void displayInfo() const override{
        cout << "Chef - ";
        Employee::displayInfo();
    }
};
class Cashier : public Employee, public IBiller{
public:
    Cashier(int id, const string &name) : Employee(id, name) {}
    void generateBill() override{
        cout << "Cashier " << name << " is generating the bill." << endl;
    }
    void displayInfo() const override{
        cout << "Cashier - ";
        Employee::displayInfo();
    }
};
class Manager : public Employee, public IOrderTaker, public IBiller{
public:
    Manager(int id, const string &name) : Employee(id, name) {}
    void takeOrder() override{
        cout << "Manager " << name << " is taking the order." << endl;
    }
    void generateBill() override{
        cout << "Manager " << name << " is generating the bill." << endl;
    }
    void displayInfo() const override{
        cout << "Manager - ";
        Employee::displayInfo();
    }
};
class Menu{
protected:
    string name;
    double baseCost;
public:
    Menu(const string &name, double cost) : name(name), baseCost(cost) {}
    virtual double calculateTotalCost() const{
        return baseCost;
    }
    virtual void displayMenu() const{
        cout << "Menu: " << name << ", Base Cost: $" << baseCost << endl;
    }
    virtual ~Menu() = default;
};
class FoodMenu : public Menu{
public:
    FoodMenu(const string &name, double cost) : Menu(name, cost) {}
    double calculateTotalCost() const override{
        return baseCost * 1.10; 
    }
    void displayMenu() const override{
        cout << "Food Menu: " << name << ", Total Cost: $" << calculateTotalCost() << endl;
    }
};
class BeverageMenu : public Menu{
public:
    BeverageMenu(const string &name, double cost) : Menu(name, cost) {}
    double calculateTotalCost() const override{
        return baseCost * 1.15;
    }
    void displayMenu() const override{
        cout << "Beverage Menu: " << name << ", Total Cost: $" << calculateTotalCost() << endl;
    }
};
int main(){
    Waiter waiter(1, "Adnan");
    Chef chef(2, "Osama");
    Cashier cashier(3, "Wasil");
    Manager manager(4, "Ahmed");
    FoodMenu foodMenu("Pizza", 10.0);
    BeverageMenu beverageMenu("Soda", 2.0);
    vector<Employee *> employees = {&waiter, &chef, &cashier, &manager};
    for (auto employee : employees){
        employee->displayInfo();
        if (auto orderTaker = dynamic_cast<IOrderTaker *>(employee)){
            orderTaker->takeOrder();
        }
        if (auto orderPreparer = dynamic_cast<IOrderPreparer *>(employee)){
            orderPreparer->prepareOrder();
        }
        if (auto biller = dynamic_cast<IBiller *>(employee)){
            biller->generateBill();
        }
    }
    vector<Menu *> menus = {&foodMenu, &beverageMenu};
    for (auto menu : menus){
        menu->displayMenu();
    }
    return 0;
}