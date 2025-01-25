#include <bits/stdc++.h>
using namespace std;

class orderBuilder {
public:
    orderBuilder(int id, string name) {
        exchange_id = id;
        exchange_name = name;
    }
    int exchange_id;
    string exchange_name;
};

class Strategy {
private:
    double order_quantity, price;
    string name;
    orderBuilder* ob;

public:
    void printmembers() {
        cout << "order_quantity: " << order_quantity << endl;
        cout << "price: " << price << endl;
        cout << "name: " << name << endl;
        cout << "exchange_name: " << ob->exchange_name << endl;
    }
    

    // Constructor initializing order quantity, price, and name, and dynamically allocating orderBuilder
    Strategy(double qnt, double pr, string nm) : order_quantity(qnt), price(pr), name(nm) {
        ob = new orderBuilder(100, "BSE");
    }

    // // Default shallow copy constructor, which will copy the pointer ob without allocating new memory
    // Strategy(const Strategy& other) {
    //     order_quantity = other.order_quantity;
    //     price = other.price;
    //     name = other.name;
    //     ob = other.ob;  // Shallow copy of the pointer
    // }

    ~Strategy() {
        // Destructor deletes ob. This will cause issues if ob is shallow copied.
        delete ob; // Free the dynamically allocated memory
    }
};

/*
by default copy constructor do shallow copy of one object to another object as it is. so if we delete obj1 then obj2 will be no longer have access to memory location so again if we try to delete obj2 it will throw error as the memory location was alraedy deleted.it creates dangling pointer problem.
in shallow copy no new location is created for dynamically allocated memory as it copies exactly.
*/

int main() {
    Strategy* obj = new Strategy(13, 13000, "saurabh"); // Correct object creation using new
    obj->printmembers();

    // Perform shallow copy (default copy constructor)
    Strategy* obj2 = new Strategy(*obj); // obj2 is a shallow copy of obj
    obj2->printmembers();

    // Delete obj, which will free the memory for `ob` (orderBuilder)
    cout << "Deleting obj..." << endl;
    delete obj; // obj is deleted, but obj2 still has a pointer to the deleted memory

    // Accessing obj2 after obj is deleted will cause undefined behavior due to dangling pointer
    cout << "Accessing obj2 after obj is deleted..." << endl;
    obj2->printmembers(); // This will cause undefined behavior (dangling pointer)

    delete obj2; // Clean up obj2, but this might cause issues due to double deletion

    return 0;
}
