#include <iostream>
#include <cstring>
using namespace std;
struct Employee
{
    int employee_id;
    char name[50];
    double salary;
};
struct Organisation
{
    char organisation_name[50];
    char organisation_number[20];
    Employee emp;
};
int main()
{
    Organisation org;
    strcpy(org.organisation_name, "NU-Fast");
    strcpy(org.organisation_number, "NUFAST123ABC");
    org.emp.employee_id = 127;
    strcpy(org.emp.name, "Linus Sebastian");
    org.emp.salary = 400000;

    cout << "The size of structure organisation : " << sizeof(Organisation) << endl;
    cout << "Organisation Name : " << org.organisation_name << endl;
    cout << "Organisation Number : " << org.organisation_number << endl;
    cout << "Employee id : " << org.emp.employee_id << endl;
    cout << "Employee name : " << org.emp.name << endl;
    cout << "Employee Salary : " << org.emp.salary << endl;
    return 0;
}
