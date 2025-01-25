/*
case 1: The problem with the default copy constructor is that both obj1 and obj2 point to the same memory location for dynamically allocated resources. 
        If we delete obj1, obj2 still points to the same memory location, which has already been deallocated. This leads to undefined behavior.

case 2: If we delete obj1 first and then attempt to delete obj2, it will result in an error because obj2 is pointing to a memory location that was already deleted by obj1. 
        This creates a double-deletion scenario and a dangling pointer problem.
*/
#include <bits/stdc++.h>
using namespace std;

class OrderBuilder {
    public:
    int exchange_id;
    string exchange_name;

    OrderBuilder(int id, string name) {
        exchange_id = id;
        exchange_name = name;
    }
};

class Strategy {
    double order_quantity, price;
    string user_name;
    OrderBuilder* ob;

    public:
    Strategy(double qnt, double prc, string name) {
        order_quantity = qnt;
        price = prc;
        user_name = name;

        OrderBuilder* obj = new OrderBuilder(100, "NSE");
        ob = obj;
    }

    ~Strategy() {
        cout << "Destructor Called: obj deleted" << endl;
        delete ob; // Ensures dynamically allocated memory is released.
    }

    void print() {
        cout << "Order Quantity: " << order_quantity << endl;
        cout << "Price: " << price << endl;
        cout << "User Name: " << user_name << endl;
        cout << "Exchange Name: " << ob->exchange_name << endl;
    }
};

int main() {
    // The dynamically allocated Strategy object (obj1) is never deleted, leading to a memory leak.
    Strategy* obj1 = new Strategy(10, 10000, "Saurabh");
    obj1->print();

    // Shallow copy using the default copy constructor
    Strategy obj2(*obj1); // Dereferencing the pointer obj1 using the * operator to pass a reference to the object.

    delete obj1;

    obj2.print();

    return 0;
}
