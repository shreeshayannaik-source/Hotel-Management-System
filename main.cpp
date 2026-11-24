#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Room {
public:
    int roomNumber;
    string roomType;
    double price;
    bool isBooked;

    Room(int number, string type, double cost) {
        roomNumber = number;
        roomType = type;
        price = cost;
        isBooked = false;
    }
};

class Customer {
public:
    string name;
    string phone;

    Customer(string n, string p) {
        name = n;
        phone = p;
    }
};

int main() {
    cout << "================================" << endl;
    cout << "     HOTEL MANAGEMENT SYSTEM" << endl;
    cout << "================================" << endl;

    return 0;
}
