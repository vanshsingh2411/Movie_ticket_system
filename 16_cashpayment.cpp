#ifndef CASHPAYMENT_CPP
#define CASHPAYMENT_CPP
#include <iostream>
#include "09_payment.cpp"
using namespace std ;

// Inheritance -- CashPayment extends Payment. Cash never fails once collected.

class CashPayment : public Payment {
 
 public:
  
    bool pay(double amount) {
        cout << "Collecting cash of Rs." << amount << " ..." << endl;
        cout << "Cash received. Payment successful." << endl;
        return true;
    }

    string getMethodName() { return "CASH"; }
};
#endif