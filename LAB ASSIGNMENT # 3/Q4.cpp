#include <iostream>
#include <string>
using namespace std;
class Employee
{
private:
    string first_name;
    string last_name;
    double monthly_salary;
public:
    Employee(string f_name, string l_name, double salary)
    {
        first_name = f_name;
        last_name = l_name;
        set_monthly_salary(salary);
    }
    void set_monthly_salary(double salary)
    {
        if (salary < 0)
            monthly_salary = 0.0;
        else
            monthly_salary = salary;
    }
    double get_yearly_salary()
    {
        return monthly_salary * 12;
    }
    void giveRaise()
    {
        monthly_salary = monthly_salary * 1.10;
    }
    void display_employee()
    {
        cout << "Employee: " << first_name << " " << last_name << endl;
        cout << "Yearly Salary: $" << get_yearly_salary() << endl;
    }
};
int main()
{
    string first_name1, last_name1, first_name2, last_name2;
    double monthly_salary1, monthly_salary2;
    cout << "Enter first name of Employee 1: ";
    cin >> first_name1;
    cout << "Enter last name of Employee 1: ";
    cin >> last_name1;
    cout << "Enter monthly salary of Employee 1: ";
    cin >> monthly_salary1;
    cout << "\nEnter first name of Employee 2: ";
    cin >> first_name2;
    cout << "Enter last name of Employee 2: ";
    cin >> last_name2;
    cout << "Enter monthly salary of Employee 2: ";
    cin >> monthly_salary2;
    Employee emp1(first_name1, last_name1, monthly_salary1);
    Employee emp2(first_name2, last_name2, monthly_salary2);
    cout << "\nInitial Salaries:" << endl;
    emp1.display_employee();
    emp2.display_employee();
    emp1.giveRaise();
    emp2.giveRaise();
    cout << "\nSalaries after 10% raise:" << endl;
    emp1.display_employee();
    emp2.display_employee();
    return 0;
}
