#ifndef SHOWSEAT_CPP
#define SHOWSEAT_CPP
#include "02_seat.cpp"


enum SeatStatus { AVAILABLE, BOOKED };

// Encapsulation -- status is private and can only change through bookSeat() / releaseSeat()
class ShowSeat {
private:
    Seat seat;
    SeatStatus status;
public:
    ShowSeat() : status(AVAILABLE) {}
    ShowSeat(Seat seat) {
        this->seat   = seat;
        this->status = AVAILABLE;
    }

    bool isAvailable() const { return status == AVAILABLE; }
    bool isBooked()    const { return status == BOOKED; }

    // returns false if already booked so the caller knows the booking failed
    bool bookSeat() {
        if (status == BOOKED) return false;
        status = BOOKED;
        return true;
    }

    void releaseSeat() { status = AVAILABLE; }

    int      getSeatNumber() const { return seat.getSeatNumber(); }
    SeatType getSeatType()   const { return seat.getType(); }
};
#endif