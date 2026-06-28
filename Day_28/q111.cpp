#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

struct Booking {
    int bookingId;
    char passengerName[50];
    int seatNumber;
    char source[30];
    char destination[30];
    double fare;
    char status[10];
};

vector<Booking> bookings;
const int TOTAL_SEATS = 50;
bool seats[TOTAL_SEATS + 1]; 

void displaySeats() {
    cout << "\n===== SEAT AVAILABILITY =====\n";
    cout << "Available (0) | Booked (1)\n\n";
    for (int i = 1; i <= TOTAL_SEATS; i++) {
        cout << (seats[i] ? "1" : "0") << " ";
        if (i % 10 == 0) cout << "\n";
    }
    cout << "\n";
}

void bookTicket() {
    Booking b;
    cout << "Enter Booking ID: ";
    cin >> b.bookingId;
    
    for (auto& booking : bookings) {
        if (booking.bookingId == b.bookingId && strcmp(booking.status, "Active") == 0) {
            cout << "Booking ID already exists!\n";
            return;
        }
    }
    
    cin.ignore();
    cout << "Enter Passenger Name: ";
    cin.getline(b.passengerName, 50);
    cout << "Enter Source: ";
    cin.getline(b.source, 30);
    cout << "Enter Destination: ";
    cin.getline(b.destination, 30);
    cout << "Enter Fare: ";
    cin >> b.fare;
    
    displaySeats();
    cout << "Enter Seat Number (1-" << TOTAL_SEATS << "): ";
    cin >> b.seatNumber;
    
    if (b.seatNumber < 1 || b.seatNumber > TOTAL_SEATS) {
        cout << "Invalid seat number!\n";
        return;
    }
    
    if (seats[b.seatNumber]) {
        cout << "Seat already booked!\n";
        return;
    }
    
    seats[b.seatNumber] = true;
    strcpy(b.status, "Active");
    bookings.push_back(b);
    cout << "\nTicket booked successfully!\n";
    cout << "Booking ID: " << b.bookingId << "\n";
    cout << "Seat Number: " << b.seatNumber << "\n";
}

void viewAllBookings() {
    if (bookings.empty()) {
        cout << "No bookings found.\n";
        return;
    }
    
    cout << "\n" << setw(8) << "BID" << setw(15) << "Name" << setw(10) << "Seat" 
         << setw(12) << "Source" << setw(12) << "Destination" << setw(8) << "Fare" 
         << setw(10) << "Status\n";
    cout << string(75, '-') << "\n";
    
    for (auto& b : bookings) {
        if (strcmp(b.status, "Active") == 0) {
            cout << setw(8) << b.bookingId << setw(15) << b.passengerName 
                 << setw(10) << b.seatNumber << setw(12) << b.source 
                 << setw(12) << b.destination << setw(8) << fixed << setprecision(2) << b.fare 
                 << setw(10) << b.status << "\n";
        }
    }
    cout << "\n";
}

void viewBooking() {
    int bid;
    cout << "Enter Booking ID: ";
    cin >> bid;
    
    for (auto& b : bookings) {
        if (b.bookingId == bid) {
            cout << "\nBooking ID: " << b.bookingId << "\n";
            cout << "Passenger Name: " << b.passengerName << "\n";
            cout << "Seat Number: " << b.seatNumber << "\n";
            cout << "Source: " << b.source << "\n";
            cout << "Destination: " << b.destination << "\n";
            cout << "Fare: " << fixed << setprecision(2) << b.fare << "\n";
            cout << "Status: " << b.status << "\n\n";
            return;
        }
    }
    cout << "Booking not found!\n";
}

void cancelBooking() {
    int bid;
    cout << "Enter Booking ID to cancel: ";
    cin >> bid;
    
    for (auto& b : bookings) {
        if (b.bookingId == bid && strcmp(b.status, "Active") == 0) {
            seats[b.seatNumber] = false;
            strcpy(b.status, "Cancelled");
            cout << "Booking cancelled successfully!\n";
            cout << "Refund Amount: " << fixed << setprecision(2) << b.fare * 0.9 << "\n";
            return;
        }
    }
    cout << "Booking not found or already cancelled!\n";
}

int main() {
    fill(seats, seats + TOTAL_SEATS + 1, false);
    
    int choice;
    while (true) {
        cout << "\n===== TICKET BOOKING SYSTEM =====\n";
        cout << "1. Book Ticket\n";
        cout << "2. View All Bookings\n";
        cout << "3. View Booking Details\n";
        cout << "4. Cancel Booking\n";
        cout << "5. View Seat Availability\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: bookTicket(); break;
            case 2: viewAllBookings(); break;
            case 3: viewBooking(); break;
            case 4: cancelBooking(); break;
            case 5: displaySeats(); break;
            case 6: cout << "Thank you!\n"; return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}