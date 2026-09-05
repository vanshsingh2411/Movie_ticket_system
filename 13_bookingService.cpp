#ifndef BOOKINGSERVICE_CPP
#define BOOKINGSERVICE_CPP
#include <vector>
#include <iostream>
#include "05_show.cpp"
#include "07_customer.cpp"
#include "10_paymentTypes.cpp"
#include "08_booking.cpp"
#include "11_priceCalculator.cpp"
#include "12_ticketPrinter.cpp"

using namespace std;

// Dependency Inversion -- receives Payment* (abstract), never creates UpiPayment/CardPayment directly

class BookingService {
 
 private :
   
    PriceCalculator priceCalculator;
    TicketPrinter   ticketPrinter;
 
 public :
  
   Booking* bookTicket(Show& show, Customer customer, vector<int> seatNumbers, Payment* payment) {
    
      vector<ShowSeat*> selectedSeats;

        // reject the whole booking if any seat is already taken
  
        for (size_t i = 0; i < seatNumbers.size(); i++) {
          
            ShowSeat* seat = show.findShowSeat(seatNumbers[i]);
          
            if (seat == nullptr) {
                cout << "Seat " << seatNumbers[i] << " does not exist. Booking rejected." << endl;
                return nullptr;
            }
          
            if (!seat->isAvailable()) {
                cout << "Seat " << seatNumbers[i] << " is already booked. Booking rejected." << endl;
                return nullptr;
            }
          
            selectedSeats.push_back(seat);
        
          }

        for (size_t i = 0; i < selectedSeats.size(); i++)
             selectedSeats[i]->bookSeat();

        double total = priceCalculator.calculateTotal(selectedSeats);
        bool   paid  = payment->pay(total);  // Runtime Polymorphism -- calls correct pay()

        if (!paid) {
            for (size_t i = 0; i < selectedSeats.size(); i++)
                selectedSeats[i]->releaseSeat();  // seats go back to AVAILABLE on failure
            Booking* booking = new Booking(customer, selectedSeats, payment, total);
            booking->fail();
            cout << "Payment failed. Seats released. Booking "
                 << booking->getBookingId() << " " << booking->getStatusString() << "." << endl;
            return booking;
        }

        Booking* booking = new Booking(customer, selectedSeats, payment, total);
        booking->confirm();
        ticketPrinter.printTicket(*booking, show);
        return booking;
    }

    void cancelBooking(Booking& booking) {
        if (booking.getStatus() != CONFIRMED) {
            cout << "Only confirmed bookings can be cancelled." << endl;
            return;
        }
        booking.cancel();
        cout << "Booking " << booking.getBookingId() << " cancelled. Seats released." << endl;
    }
};
#endif