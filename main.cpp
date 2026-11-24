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
    string customerName;
    string phone;

    Room(int number, string type, double cost) {
        roomNumber = number;
        roomType = type;
        price = cost;
        isBooked = false;
        customerName = "";
        phone = "";
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

// Save all current bookings
void saveBookings(Room rooms[], int size) {
    ofstream file("bookings.txt");

    for (int i = 0; i < size; i++) {
        if (rooms[i].isBooked) {
            file << rooms[i].roomNumber << " "
                 << rooms[i].customerName << " "
                 << rooms[i].phone << endl;
        }
    }

    file.close();
}

int main() {
    int choice, roomNumber;
    string name, phone;

    Room rooms[3] = {
        Room(101, "Single", 1000),
        Room(102, "Double", 2000),
        Room(103, "Deluxe", 3000)
    };

    // Load previous bookings
    ifstream inputFile("bookings.txt");

    while (inputFile >> roomNumber >> name >> phone) {
        for (int i = 0; i < 3; i++) {
            if (rooms[i].roomNumber == roomNumber) {
                rooms[i].isBooked = true;
                rooms[i].customerName = name;
                rooms[i].phone = phone;
            }
        }
    }

    inputFile.close();

    cout << "Previous bookings loaded successfully!\n";

    do {
        cout << "\n===== HOTEL MANAGEMENT SYSTEM =====\n";
        cout << "1. View Rooms\n";
        cout << "2. Book Room\n";
        cout << "3. Checkout\n";
        cout << "4. Exit\n";
        cout << "5. Search Room\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {

        case 1:
            for (int i = 0; i < 3; i++) {
                cout << "\nRoom Number: " << rooms[i].roomNumber;
                cout << "\nRoom Type: " << rooms[i].roomType;
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

                        cout << "Enter phone number: ";
                        cin >> phone;

                        Customer customer(name, phone);

                        rooms[i].isBooked = true;
                        rooms[i].customerName = customer.name;
                        rooms[i].phone = customer.phone;

                        saveBookings(rooms, 3);

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
                        rooms[i].customerName = "";
                        rooms[i].phone = "";

                        saveBookings(rooms, 3);

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

        case 5: {
            cout << "Enter room number to search: ";
            cin >> roomNumber;

            bool found = false;

            for (int i = 0; i < 3; i++) {
                if (rooms[i].roomNumber == roomNumber) {
                    found = true;

                    cout << "Room Number: "
                         << rooms[i].roomNumber << endl;
                    cout << "Room Type: "
                         << rooms[i].roomType << endl;
                    cout << "Price: "
                         << rooms[i].price << endl;
                    cout << "Status: "
                         << (rooms[i].isBooked ? "Booked" : "Available")
                         << endl;

                    if (rooms[i].isBooked) {
                        cout << "Customer: "
                             << rooms[i].customerName << endl;
                    }

                    break;
                }
            }

            if (!found)
                cout << "Room not found!\n";

            break;
        }

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}


                 
           
