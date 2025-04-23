#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    enum Status { UNDERGRADUATE, GRADUATE, DOCTORAL };
    virtual float getTuition(Status status, int creditHours) = 0;
    virtual ~Student() {}
};

class GraduateStudent : public Student {
private:
    string researchTopic;
public:
    float getTuition(Status status, int creditHours) override {
        switch(status) {
            case UNDERGRADUATE:
                return 200 * creditHours;
            case GRADUATE:
                return 300 * creditHours;
            case DOCTORAL:
                return 400 * creditHours;
            default:
                return 0;
        }
    }
    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }
    string getResearchTopic() const {
        return researchTopic;
    }
};

int main() {
    GraduateStudent gradStudent;
    gradStudent.setResearchTopic("Machine Learning Applications");
    
    cout << "Graduate tuition for 12 credit hours: $" 
         << gradStudent.getTuition(Student::GRADUATE, 12) << endl;
    cout << "Doctoral tuition for 9 credit hours: $" 
         << gradStudent.getTuition(Student::DOCTORAL, 9) << endl;
    cout << "Research Topic: " << gradStudent.getResearchTopic() << endl;

    return 0;
}