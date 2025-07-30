#include <iostream>
#include <string>

using namespace std;

class Room {
private:
    int roomNumber;
    string type;
    bool available;
    string reservedPerson;
    string reservedPersonPhoneNumber;
    string reservedPersonAddress;

public:
    Room(int roomNumber, const string& type)
        : roomNumber(roomNumber), type(type), available(true) {}

    int getRoomNumber() const {
        return roomNumber;
    }

    string getType() const {
        return type;
    }

    bool isAvailable() const {
        return available;
    }

    void bookRoom(const string& personName, const string& phoneNumber, const string& address) {
        if (available) {
            available = false;
            reservedPerson = personName;
            reservedPersonPhoneNumber = phoneNumber;
            reservedPersonAddress = address;
            cout << "Room " << roomNumber << " booked successfully for " << personName << ".\n";
        }
        else {
            cout << "Room " << roomNumber << " is not available.\n";
        }
    }

    void displayRoomInfo() const {
        std::cout << "Room Number: " << roomNumber << " - Type: " << type;
        if (!available) {
            cout << " - Reserved for: " << reservedPerson << "\n";
            cout << "Phone Number: " << reservedPersonPhoneNumber << "\n";
            cout << "Address: " << reservedPersonAddress << "\n";
        }
    }

    double calculateBill() const {
        double rate = 0.0;
        if (type == "Single AC Room") {
            rate = 120.0;
        }
        else if (type == "Single Non AC Room") {
            rate = 100.0;
        }
        else if (type == "Double AC Room") {
            rate = 200.0;
        }
        else if (type == "Double Non AC Room") {
            rate = 150.0;
        }
        else if (type == "Twin AC Room") {
            rate = 200.0;
        }
        else if (type == "Twin Non AC Room") {
            rate = 150.0;
        }
        else if (type == "Family AC Room") {
            rate = 300.0;
        }
        else if (type == "Standard Room") {
            rate = 400.0;
        }
        else if (type == "Deluxe Room") {
            rate = 500.0;
        }
        return rate;
    }
};

class Hotel {
private:
    Room rooms[9] = {
       Room(1, "Single AC Room"),
       Room(2, "Single Non AC Room"),
       Room(3, "Double AC Room"),
       Room(4, "Double Non AC Room"),
       Room(5, "Twin AC Room"),
       Room(6, "Twin Non AC Room"),
       Room(7, "Family AC Room"),
       Room(8, "Standard Room"),
       Room(9, "Deluxe Room")
    };

public:
    void displayAvailableRooms() const {
        cout << "\n===== Available Rooms =====\n";
        for (const Room& room : rooms) {
            if (room.isAvailable()) {
                room.displayRoomInfo();
            }
        }
        cout << "===========================\n";
    }

    void bookRoom(int roomNumber, const string& personName, const string& phoneNumber, const string& address) {
        if (roomNumber >= 1 && roomNumber <= 9) {
            rooms[roomNumber - 1].bookRoom(personName, phoneNumber, address);
        }
        else {
            cout << "Room " << roomNumber << " does not exist.\n";
        }
    }

    void displayReservedPersonDetails(int roomNumber) const {
        if (roomNumber >= 1 && roomNumber <= 9) {
            rooms[roomNumber - 1].displayRoomInfo();
        }
        else {
            cout << "Room " << roomNumber << " is not booked.\n";
        }
    }

    double calculateBill(int roomNumber) const {
        if (roomNumber >= 1 && roomNumber <= 9) {
            return rooms[roomNumber - 1].calculateBill();
        }
        else {
            cout << "Room " << roomNumber << " is not booked.\n";
            return 0.0;
        }
    }
};

int main() {
    Hotel hotel;
    string username, password;
    string personName, phoneNumber, address;
    int choice, roomNumber;

    cout << "Login to the Hotel Room Booking System\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username != "senu" || password != "1234") {
        cout << "Invalid credentials. Exiting...\n";
        return 1;
    }

    while (true) {
        cout << "\n===== Hotel Room Booking System =====\n";
        cout << "1. Check Room Availability\n";
        cout << "2. Book a Room\n";
        cout << "3. View Reserved Person Details\n";
        cout << "4. Generate Bill\n";
        cout << "5. Exit\n";
        cout << "===================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            hotel.displayAvailableRooms();
            break;
        case 2:
            cout << "Enter the Room Number to book: ";
            cin >> roomNumber;
            cout << "Enter your name: ";
            cin >> personName;
            cout << "Enter your phone number: ";
            cin >> phoneNumber;
            cout << "Enter your address: ";
            cin >> address;
            hotel.bookRoom(roomNumber, personName, phoneNumber, address);
            break;
        case 3:
            cout << "Enter the Room Number to view reserved person details: ";
            cin >> roomNumber;
            hotel.displayReservedPersonDetails(roomNumber);
            break;
        case 4:
            cout << "Enter the Room Number to calculate the bill: ";
            cin >> roomNumber;
            cout << "Total Bill Amount for Room " << roomNumber << ": $" << hotel.calculateBill(roomNumber) << "\n";
            break;
        case 5:
            cout << "Exiting the program. Thank you!\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}