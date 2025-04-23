#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PatientRecord {
private:
    string name;
    string id;
    string dob;
    vector<string> medicalHistory;
    vector<string> currentTreatments;
    vector<string> billingDetails;
public:
    PatientRecord(string n, string i, string d) : name(n), id(i), dob(d) {}
    string getPublicData() {
        return "Name: " + name + ", ID: " + id + ", DOB: " + dob;
    }
    vector<string> getMedicalData() {
        return medicalHistory;
    }
    void updateMedicalHistory(string entry) {
        medicalHistory.push_back(entry);
    }
    void addBillingDetails(string detail) {
        billingDetails.push_back(detail);
    }
    vector<string> getBillingDetails() {
        return billingDetails;
    }
};

class Doctor {
public:
    void accessMedicalHistory(PatientRecord &record, string entry) {
        record.updateMedicalHistory(entry);
    }
    void viewMedicalHistory(PatientRecord &record) {
        vector<string> history = record.getMedicalData();
        for (const auto &entry : history) {
            cout << entry << endl;
        }
    }
};

class Billing {
public:
    void addBillingDetail(PatientRecord &record, string detail) {
        record.addBillingDetails(detail);
    }
    void viewBillingDetails(PatientRecord &record) {
        vector<string> billing = record.getBillingDetails();
        for (const auto &detail : billing) {
            cout << detail << endl;
        }
    }
};

class Receptionist {
public:
    void viewPublicData(PatientRecord &record) {
        cout << record.getPublicData() << endl;
    }
};

int main() {
    PatientRecord patient("Muhammad Bin ISmail", "12345", "01/01/1980");
    Doctor doctor;
    Billing billing;
    Receptionist receptionist;

    doctor.accessMedicalHistory(patient, "Initial checkup");
    billing.addBillingDetail(patient, "Payment received: 100");

    cout << "Doctor accessing medical history:" << endl;
    doctor.viewMedicalHistory(patient);

    cout << "Billing accessing billing details:" << endl;
    billing.viewBillingDetails(patient);

    cout << "Receptionist accessing public data:" << endl;
    receptionist.viewPublicData(patient);

    return 0;
}