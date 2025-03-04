#include <iostream>
using namespace std;
class Student
{
private:
    const int roll_no;
public:
    Student(int roll) : roll_no(roll) {}
    void displayStudentDetails() const
    {
        cout << "Roll Number: " << roll_no << endl;
    }
};
int main()
{
    int roll;
    cout << "Enter Roll Number: ";
    cin >> roll;
    Student student(roll);
    student.displayStudentDetails();
    return 0;
}
