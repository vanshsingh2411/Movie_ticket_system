#ifndef PAYMENT_CPP
#define PAYMENT_CPP
#include <string>
using namespace std;

//  Abstraction -- Payment defines WHAT to do (pay), not HOW each method does it.
//  Interface Segregation -- only pay() is required. No refund() forced on Cash/UPI.

class Payment {

  public:

    virtual bool  pay( double amount )    = 0;  // pure virtual -- must be overridden
    virtual string getMethodName()  = 0;
    virtual ~Payment() {}

 };

 #endif