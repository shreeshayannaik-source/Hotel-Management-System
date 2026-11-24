#include<fstream>
#include <iostream>
#include <string>
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
    int choice, roomNumber;
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
        cout << "3. Checkout\n";
        cout << "4. Exit\n";
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

        case 2: {
            cout << "Enter room number: ";
            cin >> roomNumber;

            bool found = false;

            for (int i = 0; i < 3; i++) {
                if (rooms[i].roomNumber == roomNumber) {
                    found = true;

                    if (!rooms[i].isBooked) {
                        cout << "Enter customer name: ";
                        cin >> name;

                        cout << "Enter phone: ";
                        cin >> phone;

                        Customer customer(name, phone);
                        rooms[i].isBooked = true;
                        ofstream file("booking.txt", ios::app);

                        file<< roomNumber <<" "
                            << name <<" "
                            << phone << end1;
                        file.close();

                        cout << "Room booked successfully!\n";
                    } else {
                        cout << "Room already booked!\n";
                    }
                    break;
                }
            }

            if (!found)
                cout << "Room not found!\n";

            break;
        }

        case 3: {
            cout << "Enter room number for checkout: ";
            cin >> roomNumber;

            bool found = false;

            for (int i = 0; i < 3; i++) {
                if (rooms[i].roomNumber == roomNumber) {
                    found = true;

                    if (rooms[i].isBooked) {
                        rooms[i].isBooked = false;
                        cout << "Checkout successful!\n";
                    } else {
                        cout << "Room is not booked!\n";
                    }
                    break;
                }
            }

            if (!found)
                cout << "Room not found!\n";

            break;
        }

        case 4:
            cout << "Thank you for using our system!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}


                 
           
