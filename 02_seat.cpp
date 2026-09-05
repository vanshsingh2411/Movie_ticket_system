
#ifndef SEAT_CPP
#define SEAT_CPP
#include <string>
using namespace std;

 enum SeatType { SILVER, GOLD, PLATINUM };

 string seatTypeToString(SeatType type) {
    if (type == SILVER)   return "SILVER";
    if (type == GOLD)     return "GOLD";
    return "PLATINUM";
 }

// Encapsulation -- seat data is private, accessed only through getters

class Seat {
 private:
     int seatNumber;
     SeatType type;
 public:
  
    Seat() : seatNumber(0), type(SILVER) {}
    
    Seat(int seatNumber, SeatType type) {
        this->seatNumber = seatNumber;
        this->type       = type;
    }
    
    int  getSeatNumber() const { return seatNumber; }
    
    SeatType getType()  const { return type; }

  };
#endif