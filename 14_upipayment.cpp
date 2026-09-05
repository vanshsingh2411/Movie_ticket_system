#ifndef UPIPAYMENT_CPP
#define UPIPAYMENT_CPP
#include <iostream>
#include <cstdlib>
#include "09_payment.cpp"
using namespace std;

// Inheritance -- UpiPayment extends Payment
// Runtime Polymorphism -- pay() here is called when Payment* points to a UpiPayment object

class UpiPayment : public Payment {
 
 private :
     string upiId;

 public :
   
 UpiPayment(string upiId) { this->upiId = upiId; }

 bool pay(double amount) {

      cout << "Sending Rs." << amount << " via UPI (" << upiId << ") ..." << endl ;

      if( rand() % 5 == 0) {  // ~20% simulated bank decline for demo
            
            cout << "UPI payment declined by bank." << endl ;
            return false ;
            
      }

        cout << "UPI payment successful." << endl ;
        return true ;
  
 }

  string getMethodName() { return "UPI"; }

};

#endif