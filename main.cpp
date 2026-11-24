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
    int choice;
    int roomNumber;
    string name, phone;

    Room rooms[3] = {
        Room(101, "Single", 1000),
        Room(102, "Double", 2000),
        Room(103, "Deluxe", 3000)
    };

    do {
        cout << "\n===== HOTEL MANAGEMENT SYSTEM =====\n";
        cout << "1. View Rooms\n";
        cout << "2. Book Room\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < 3; i++) {
                cout << "\nRoom: " << rooms[i].roomNumber;
                cout << "\nType: " << rooms[i].roomType;
                cout << "\nPrice: " << rooms[i].price;
                cout << "\nStatus: "
                     << (rooms[i].isBooked ? "Booked" : "Available")
                     << endl;
            }
            break;

        case 2:
            cout << "Enter room number: ";
            cin >> roomNumber;

            for (int i = 0; i < 3; i++) {
                if (rooms[i].roomNumber == roomNumber) {
                    if (!rooms[i].isBooked) {
                        cout << "Enter customer name: ";
                        cin >> name;

                        cout << "Enter phone number: ";
                        cin >> phone;

                        Customer customer(name, phone);
                        rooms[i].isBooked = true;

                        cout << "\nRoom booked successfully!\n";
                    } else {
                        cout << "Sorry! Room is already booked.\n";
                    }
                    break;
                }
            }
            break;

        case 3:
            cout << "Thank you!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
