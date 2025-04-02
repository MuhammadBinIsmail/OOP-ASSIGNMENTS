#include <iostream>
#include <string>
#include <vector>
#include <map> 
using namespace std;
class Person
{
protected:
    string name;
    string id;
    string address;
    string phone;
    string email;
public:
    Person(string n, string i, string a, string p, string e)
        : name(n), id(i), address(a), phone(p), email(e) {}
    string getName() const { return name; }
    string getId() const { return id; }
    virtual void display()
    {
        cout << "\nName: " << name
             << "\nID: " << id
             << "\nAddress: " << address
             << "\nPhone: " << phone
             << "\nEmail: " << email;
    }
    virtual void update()
    {
        cout << "Enter new address: ";
        getline(cin >> ws, address);
        cout << "Enter new phone: ";
        getline(cin, phone);
        cout << "Enter new email: ";
        getline(cin, email);
    }
};
class Student : public Person
{
    vector<string> courses;
    map<string, char> grades;
    double gpa;
    int year;
public:
    Student(string n, string i, string a, string p, string e, double g, int y)
        : Person(n, i, a, p, e), gpa(g), year(y) {}
    void display() override
    {
        Person::display();
        cout << "\nGPA: " << gpa
             << "\nEnrollment Year: " << year
             << "\nCourses: ";
        for (const auto &c : courses)
            cout << c << ", ";
    }
    void enrollCourse(string course)
    {
        courses.push_back(course);
        grades[course] = 'N';
    }
    void assignGrade(string course, char grade)
    {
        if (grades.find(course) != grades.end())
        {
            grades[course] = grade;
        }
    }
    char getGrade(string course)
    {
        return grades[course];
    }
};
class Professor : public Person
{
    string department;
    double salary;
    vector<string> coursesTaught;
public:
    Professor(string n, string i, string a, string p, string e, string d, double s)
        : Person(n, i, a, p, e), department(d), salary(s) {}

    void display() override
    {
        Person::display();
        cout << "\nDepartment: " << department
             << "\nSalary: $" << salary
             << "\nCourses Taught: ";
        for (const auto &c : coursesTaught)
            cout << c << ", ";
    }

    void assignCourse(string course)
    {
        coursesTaught.push_back(course);
    }
};
class Staff : public Person
{
    string department;
    string position;
    double salary;

public:
    Staff(string n, string i, string a, string p, string e, string d, string pos, double s)
        : Person(n, i, a, p, e), department(d), position(pos), salary(s) {}

    void display() override
    {
        Person::display();
        cout << "\nDepartment: " << department
             << "\nPosition: " << position
             << "\nSalary: $" << salary;
    }
};
class Course
{
    string code;
    string name;
    int credits;
    Professor *instructor;
    vector<Student *> students;
    string schedule;
public:
    Course(string c, string n, int cred, string sched)
        : code(c), name(n), credits(cred), instructor(nullptr), schedule(sched) {}
    void assignInstructor(Professor *prof)
    {
        instructor = prof;
        prof->assignCourse(name);
    }
    void registerStudent(Student *student)
    {
        students.push_back(student);
        student->enrollCourse(name);
    }
    void calculateGrades()
    {
        cout << "\n=== Grading for " << code << " - " << name << " ===";
        for (auto student : students)
        {
            cout << "\nEnter grade for " << student->getName() << " (A-F): ";
            char grade;
            cin >> grade;
            student->assignGrade(name, grade);
        }
    }
    void display()
    {
        cout << "\n\nCourse: " << code << " - " << name
             << "\nCredits: " << credits
             << "\nSchedule: " << schedule;
        if (instructor)
            cout << "\nInstructor: " << instructor->getName();
        cout << "\nEnrolled Students (" << students.size() << "):";
        for (const auto &s : students)
        {
            cout << "\n- " << s->getName() << " (ID: " << s->getId() << ")";
        }
    }
};
int main()
{
    cout << "=== University Management System ===\n";
    cout << "\nEnter Professor Details:";
    string name, id, address, phone, email, dept;
    double salary;
    cout << "\nName: ";
    getline(cin >> ws, name);
    cout << "ID: ";
    getline(cin, id);
    cout << "Address: ";
    getline(cin, address);
    cout << "Phone: ";
    getline(cin, phone);
    cout << "Email: ";
    getline(cin, email);
    cout << "Department: ";
    getline(cin, dept);
    cout << "Salary: ";
    cin >> salary;
    Professor prof(name, id, address, phone, email, dept, salary);
    cin.ignore();
    cout << "\nEnter Staff Details:";
    string position;
    cout << "\nName: ";
    getline(cin, name);
    cout << "ID: ";
    getline(cin, id);
    cout << "Address: ";
    getline(cin, address);
    cout << "Phone: ";
    getline(cin, phone);
    cout << "Email: ";
    getline(cin, email);
    cout << "Department: ";
    getline(cin, dept);
    cout << "Position: ";
    getline(cin, position);
    cout << "Salary: ";
    cin >> salary;
    Staff staff(name, id, address, phone, email, dept, position, salary);
    cin.ignore();
    cout << "\nEnter Student Details:";
    double gpa;
    int year;
    cout << "\nName: ";
    getline(cin, name);
    cout << "ID: ";
    getline(cin, id);
    cout << "Address: ";
    getline(cin, address);
    cout << "Phone: ";
    getline(cin, phone);
    cout << "Email: ";
    getline(cin, email);
    cout << "GPA: ";
    cin >> gpa;
    cout << "Enrollment Year: ";
    cin >> year;
    Student student(name, id, address, phone, email, gpa, year);
    cin.ignore();
    cout << "\nEnter Course Details:";
    string code, cname, sched;
    int creds;
    cout << "\nCourse Code: ";
    getline(cin, code);
    cout << "Course Name: ";
    getline(cin, cname);
    cout << "Credits: ";
    cin >> creds;
    cin.ignore();
    cout << "Schedule: ";
    getline(cin, sched);
    Course course(code, cname, creds, sched);
    course.assignInstructor(&prof);
    course.registerStudent(&student);
    course.calculateGrades();
    cout << "\n\n=== SYSTEM OVERVIEW ===";
    prof.display();
    staff.display();
    student.display();
    course.display();
    return 0;
}