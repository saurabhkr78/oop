#include <bits/stdc++.h>
using namespace std;

class orderBuilder {
public:
    void display() {
        cout << "orderBuilder object" << endl;
    }
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
    }

    Strategy(double order_quantity, double price, string name) {
        this->order_quantity = order_quantity;
        this->price = price;
        this->name = name;
        ob = new orderBuilder(); // Dynamically allocating memory for ob
    }


    ~Strategy() {
        delete ob; // Free the dynamically allocated memory
    }
};

/*
by default copy constructor do shallow copy of one object to another object as it is. so if we delete obj1 then obj2 will be no longer have access to memory location so again if we try to delete obj2 it will throw error as the memory location was alraedy deleted.it creates dangling pointer problem.
*/

int main()
{
    Strategy obj(13, 13000, "saurabh");
    obj.printmembers();
    
    // obj1 copied to obj2 using shallow copy constructor
    Strategy obj2(obj);
    obj2.printmembers();

    // Now delete obj, which will free the memory for `ob` (orderBuilder)
    cout << "Deleting obj..." << endl;
    // obj goes out of scope and the destructor is called for obj, deleting ob.
    
    // Accessing obj2 will now cause undefined behavior since ob in obj2 points to deleted memory.
    cout << "Accessing obj2 after obj is deleted: " << endl;
    obj2.printmembers(); // This may crash or cause unexpected behavior.
    
    return 0;
}
