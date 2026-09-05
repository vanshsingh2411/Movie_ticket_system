#ifndef TICKETPRINTER_CPP
#define TICKETPRINTER_CPP
#include <iostream>
#include <vector>
#include "08_booking.cpp"
#include "05_show.cpp"

using namespace std;

// Single Responsibility -- only prints the ticket. Layout changes don't touch Booking.
class TicketPrinter {
public:
    void printTicket(Booking& booking, Show& show) const {
        cout << "\n========== TICKET ==========" << endl;
        cout << "Booking ID : " << booking.getBookingId() << endl;
        cout << "Customer   : " << booking.getCustomer().getName() << endl;
        cout << "Movie      : " << show.getMovie()->getTitle() << endl;
        cout << "Screen     : " << show.getScreen()->getScreenNumber() << endl;
        cout << "Show Time  : " << show.getStartTime() << endl;
        cout << "Seats      : ";
        vector<ShowSeat*> seats = booking.getSeats();
        for (size_t i = 0; i < seats.size(); i++)
            cout << seats[i]->getSeatNumber() << " ";
        cout << endl;
        cout << "Paid via   : " << booking.getPayment()->getMethodName() << endl;
        cout << "Total      : Rs." << booking.getTotalAmount() << endl;
        cout << "Status     : " << booking.getStatusString() << endl;
        cout << "============================\n" << endl;
    }
};
#endif