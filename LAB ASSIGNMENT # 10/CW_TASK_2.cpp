#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_EMPLOYEES = 100;
const string FILENAME = "employees.txt";
struct Employee {
    int id;
    char name[50];
    char designation[50];
    int yearsOfService;
};
class EmployeeCRUD {
private:
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    void loadData() {
        ifstream file(FILENAME);
        count = 0;
        if (file.is_open()) {
            while (file >> employees[count].id) {
                file.ignore(); 
                file.getline(employees[count].name, 50, ',');
                file.getline(employees[count].designation, 50, ',');
                file >> employees[count].yearsOfService;
                count++;
                if (count >= MAX_EMPLOYEES) break;
            }
            file.close();
        } else {
            initializeDummyData();
        }
    }
    void saveData() {
        ofstream file(FILENAME);
        if (file.is_open()) {
            for (int i = 0; i < count; i++) {
                file << employees[i].id << ","
                     << employees[i].name << ","
                     << employees[i].designation << ","
                     << employees[i].yearsOfService << "\n";
            }
            file.close();
        }
    }
    void initializeDummyData() {
        addEmployee(1, "Wasy", "Manager", 3);
        addEmployee(2, "Ahmed", "Developer", 1);
        addEmployee(3, "Ayesha", "Manager", 5);
        addEmployee(4, "Bilal", "Designer", 2);
        addEmployee(5, "Wasil", "Manager", 2);
        saveData();
    }
    void addEmployee(int id, const char* name, const char* designation, int years) {
        if (count < MAX_EMPLOYEES) {
            employees[count].id = id;
            strncpy(employees[count].name, name, 49);
            strncpy(employees[count].designation, designation, 49);
            employees[count].yearsOfService = years;
            count++;
        }
    }
public:
    EmployeeCRUD() {
        loadData();
    }
    void findManagersWithMinYears(Employee result[], int &resultCount) {
        resultCount = 0;
        for (int i = 0; i < count; i++) {
            if (strcmp(employees[i].designation, "Manager") == 0 && 
                employees[i].yearsOfService >= 2) {
                result[resultCount++] = employees[i];
            }
        }
    }
    void deleteAllExcept(Employee toKeep[], int keepCount) {
        count = 0;
        for (int i = 0; i < keepCount; i++) {
            employees[count++] = toKeep[i];
        }
        saveData();
        loadData(); 
    }
    void duplicateWithIncrements(Employee toDuplicate[], int duplicateCount) {
        if (count + duplicateCount > MAX_EMPLOYEES) {
            cout << "Cannot duplicate - exceed maximum employee count\n";
            return;
        }
        int maxId = 0;
        for (int i = 0; i < count; i++) {
            if (employees[i].id > maxId) {
                maxId = employees[i].id;
            }
        }
        for (int i = 0; i < duplicateCount; i++) {
            employees[count].id = ++maxId;
            strcpy(employees[count].name, toDuplicate[i].name);
            strcpy(employees[count].designation, toDuplicate[i].designation);
            employees[count].yearsOfService = toDuplicate[i].yearsOfService + 1;
            count++;
        }
        saveData();
        loadData(); 
    }
    void displayAllEmployees() {
        cout << "ID\tName\tDesignation\tYears of Service\n";
        cout << "\n";
        for (int i = 0; i < count; i++) {
            cout << employees[i].id << "\t" 
                 << employees[i].name << "\t"
                 << employees[i].designation << "\t\t"
                 << employees[i].yearsOfService << "\n";
        }
        cout << endl;
    }
    void displayEmployees(Employee emps[], int empCount) {
        cout << "ID\tName\tDesignation\tYears of Service\n";
        cout << "\n";
        for (int i = 0; i < empCount; i++) {
            cout << emps[i].id << "\t" 
                 << emps[i].name << "\t"
                 << emps[i].designation << "\t\t"
                 << emps[i].yearsOfService << "\n";
        }
        cout << endl;
    }
};
int main() {
    EmployeeCRUD crud;
    Employee managers[MAX_EMPLOYEES];
    int managerCount = 0;

    cout << "Initial Data:\n";
    crud.displayAllEmployees();
    cout << "\nFind managers with ≥2 years service\n";
    crud.findManagersWithMinYears(managers, managerCount);
    crud.displayEmployees(managers, managerCount);
    cout << "Delete all except these managers\n";
    crud.deleteAllExcept(managers, managerCount);
    cout << "Data after deletion:\n";
    crud.displayAllEmployees();
    cout << "Duplicate with incremented IDs and years\n";
    crud.duplicateWithIncrements(managers, managerCount);
    cout << "Final data:\n";
    crud.displayAllEmployees();
    return 0;
}