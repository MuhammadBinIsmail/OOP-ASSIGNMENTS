#include <iostream>
#include <string>
using namespace std;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int bookedSeats;
    string* passengerList;
public:
    Flight(string num, string dep, string arr, int cap) : flightNumber(num), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {
        passengerList = new string[capacity];
    }
    ~Flight() {
        delete[] passengerList;
    }
    bool bookSeat(string passengerId) {
        if (bookedSeats >= capacity) return false;
        passengerList[bookedSeats] = passengerId;
        bookedSeats++;
        return true;
    }
    bool cancelSeat(string passengerId) {
        for (int i = 0; i < bookedSeats; i++) {
            if (passengerList[i] == passengerId) {
                for (int j = i; j < bookedSeats-1; j++) {
                    passengerList[j] = passengerList[j+1];
                }
                bookedSeats--;
                return true;
            }
        }
        return false;
    }
    bool upgradeSeat(string passengerId) {
        for (int i = 0; i < bookedSeats; i++) {
            if (passengerList[i] == passengerId) return true;
        }
        return false;
    }
    string getFlightDetails() {
        return "Flight " + flightNumber + ": " + departure + " to " + arrival + ", Capacity: " + to_string(capacity) + ", Booked: " + to_string(bookedSeats);
    }
};

class Passenger {
private:
    string id;
    string name;
public:
    Passenger(string i, string n) : id(i), name(n) {}
    bool requestBooking(Flight& flight) {
        return flight.bookSeat(id);
    }
    bool requestCancellation(Flight& flight) {
        return flight.cancelSeat(id);
    }
    bool requestUpgrade(Flight& flight) {
        return flight.upgradeSeat(id);
    }
    string getPassengerDetails() {
        return "Passenger: " + name + " (ID: " + id + ")";
    }
};

int main() {
    Flight flight1("F123", "New York", "London", 150);
    Flight flight2("F456", "Tokyo", "Paris", 200);

    Passenger passenger1("P001", "Ali");
    Passenger passenger2("P002", "RAfay");

    cout << flight1.getFlightDetails() << endl;
    cout << flight2.getFlightDetails() << endl;

    passenger1.requestBooking(flight1);
    passenger2.requestBooking(flight1);
    passenger1.requestBooking(flight2);

    cout << "After bookings:" << endl;
    cout << flight1.getFlightDetails() << endl;
    cout << flight2.getFlightDetails() << endl;

    passenger1.requestCancellation(flight1);

    cout << "After cancellation:" << endl;
    cout << flight1.getFlightDetails() << endl;

    return 0;
}