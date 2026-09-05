#ifndef SCREEN_CPP
#define SCREEN_CPP
#include <vector>
#include "02_seat.cpp"
using namespace std;

// Composition -- Screen owns its Seats. If Screen is gone, the Seats go too.
class Screen {
private:
    int screenNumber;
    vector<Seat> seats;
public:
    Screen() : screenNumber(0) {}
    Screen(int screenNumber) {
        this->screenNumber = screenNumber;
    }
    void addSeat(const Seat& seat) { seats.push_back(seat); }
    vector<Seat>& getSeats()       { return seats; }
    int getScreenNumber() const    { return screenNumber; }
};
#endif