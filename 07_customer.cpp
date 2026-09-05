#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP
#include <string>
using namespace std;

// Encapsulation -- name and phone are private, read-only from outside
class Customer {
private:
    string name;
    string phone;
public:
    Customer() {}
    Customer(string name, string phone) {
        this->name  = name;
        this->phone = phone;
    }
    string getName()  const { return name; }
    string getPhone() const { return phone; }
};
#endif