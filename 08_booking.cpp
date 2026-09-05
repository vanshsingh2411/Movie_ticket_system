#ifndef BOOKING_CPP
#define BOOKING_CPP
#include <vector>
#include <string>
#include "07_customer.cpp"
#include "06_showseat.cpp"
#include "09_payment.cpp"
using namespace std;

enum BookingStatus { PENDING, CONFIRMED, FAILED, CANCELLED };

string bookingStatusToString(BookingStatus s) {
    if (s == PENDING)   return "PENDING";
    if (s == CONFIRMED) return "CONFIRMED";
    if (s == FAILED)    return "FAILED";
    return "CANCELLED";
}

// Single Responsibility -- Booking only stores data and tracks its own status
class Booking {
private:
    static int nextBookingId;  // static: shared across all objects, gives unique IDs from 1001
    int bookingId;
    Customer customer;
    vector<ShowSeat*> seats;   // Association: ShowSeats live inside Show, not here
    Payment* payment;          // Composition: this payment record belongs to this booking
    double totalAmount;
    BookingStatus status;
public:
    Booking() : payment(nullptr), totalAmount(0), status(PENDING) {}

    Booking(Customer customer, vector<ShowSeat*> seats, Payment* payment, double totalAmount) {
        this->bookingId   = nextBookingId++;  // 'this->' separates member from parameter
        this->customer    = customer;
        this->seats       = seats;
        this->payment     = payment;
        this->totalAmount = totalAmount;
        this->status      = PENDING;
    }

    void confirm() { status = CONFIRMED; }
    void fail()    { status = FAILED; }
    void cancel() {
        for (size_t i = 0; i < seats.size(); i++)
            seats[i]->releaseSeat();
        status = CANCELLED;
    }

    int               getBookingId()    const { return bookingId; }
    Customer          getCustomer()     const { return customer; }
    vector<ShowSeat*> getSeats()        const { return seats; }
    Payment*          getPayment()      const { return payment; }
    double            getTotalAmount()  const { return totalAmount; }
    BookingStatus     getStatus()       const { return status; }
    string            getStatusString() const { return bookingStatusToString(status); }
};
int Booking::nextBookingId = 1001;
#endif