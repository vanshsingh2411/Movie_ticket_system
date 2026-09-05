#ifndef PRICECALCULATOR_CPP
#define PRICECALCULATOR_CPP
#include <vector>
#include "06_showseat.cpp"
using namespace std;

// Single Responsibility -- only job here is pricing math, nothing else
class PriceCalculator {
private:
    static const double SILVER_PRICE;
    static const double GOLD_PRICE;
    static const double PLATINUM_PRICE;
public:
    double priceForSeatType(SeatType type) const {
        if (type == SILVER)   return SILVER_PRICE;
        if (type == GOLD)     return GOLD_PRICE;
        return PLATINUM_PRICE;
    }

    double calculateTotal(vector<ShowSeat*> seats) const {
        double total = 0;
        for (size_t i = 0; i < seats.size(); i++)
            total += priceForSeatType(seats[i]->getSeatType());
        return total;
    }
};
const double PriceCalculator::SILVER_PRICE   = 150.0;
const double PriceCalculator::GOLD_PRICE     = 250.0;
const double PriceCalculator::PLATINUM_PRICE = 400.0;
#endif