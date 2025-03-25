#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Student
{
protected:
    string name;
    int rollNumber;
    string department;
public:
    Student(string n, int roll, string dept) : name(n), rollNumber(roll), department(dept) {}
    void displayStudentInfo()
    {
        cout << "\nStudent Details:\n";
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Department: " << department << endl;
    }
};
class Marks : public Student
{
protected:
    vector<string> courses;
    vector<int> marks;
public:
    Marks(string n, int roll, string dept, vector<string> crs, vector<int> mks)
        : Student(n, roll, dept), courses(crs), marks(mks) {}
    void displayMarks()
    {
        cout << "\nMarks Obtained:\n";
        for (int i = 0; i < courses.size(); i++)
        {
            cout << courses[i] << ": " << marks[i] << endl;
        }
    }
};
class Result : public Marks
{
public:
    Result(string n, int roll, string dept, vector<string> crs, vector<int> mks)
        : Marks(n, roll, dept, crs, mks) {}

    void displayResult()
    {
        int total = 0;
        for (int mark : marks)
        {
            total += mark;
        }
        float average = static_cast<float>(total) / marks.size();

        cout << "\nResult:\n";
        cout << "Total Marks: " << total << endl;
        cout << "Average Marks: " << average << endl;
    }
};
int main()
{
    string name, department;
    int roll, numCourses;
    vector<string> courses;
    vector<int> marks;
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter roll number: ";
    cin >> roll;
    cin.ignore();
    cout << "Enter department: ";
    getline(cin, department);
    cout << "Enter number of courses: ";
    cin >> numCourses;
    cin.ignore();
    for (int i = 0; i < numCourses; i++)
    {
        string course;
        int mark;
        cout << "Enter course " << i + 1 << " name: ";
        getline(cin, course);
        cout << "Enter marks for " << course << ": ";
        cin >> mark;
        cin.ignore();
        courses.push_back(course);
        marks.push_back(mark);
    }
    Result studentResult(name, roll, department, courses, marks);
    studentResult.displayStudentInfo();
    studentResult.displayMarks();
    studentResult.displayResult();

    return 0;
}