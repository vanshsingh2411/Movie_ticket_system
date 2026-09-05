#ifndef PAYMENTTYPE_CPP
#define PAYMENTTYPE_CPP
#include "14_upipayment.cpp"
#include "15_cardpayment.cpp"
#include "16_cashpayment.cpp"

 using namespace std; 

 enum PaymentMethod { UPI, CARD, CASH } ;

// Open/Closed Principle -- to add NetBanking, just create NetBankingPayment.cpp
// and add one new branch here. BookingService never needs to change.

Payment* createPayment(PaymentMethod method) {
    
  if( method == UPI) {
      
    UpiPayment* upiObject =  new UpiPayment("random123@upi");
        return upiObject;
    }

    if (method == CARD){
       return new CardPayment("**** **** **** 9053");
    }
    
    return new CashPayment();

 }
#endif