/*
--object slicing: when we assign the derived class object to the base class object, the derived class object is sliced off and only the base class object is copied.
--this is because the base class object is smaller in size than the derived class object.

--to avoid object slicing, we need to use pointers or references.
--when we use pointers or references, the base class pointer or reference will point to the derived class object.

--without reference or pointer, the base class object will be copied and the derived class object will be sliced off.
--with reference or pointer, the base class object will point to the derived class object.


*/
#include<bits/stdc++.h> 
using namespace std;

// Base class with a virtual function
class Base {
public:
    // Virtual function to enable runtime polymorphism
    virtual void display() {
        cout << "Base Display" << endl;
    }
};

// Derived class inheriting from Base
class Derived : public Base {
public:
    // Override the display() function from the Base class
    void display() {
        cout << "Derived Display" << endl;
    }

    // Additional function specific to the Derived class
    void show() {
        cout << "Derived Show" << endl;
    }
};

// Function to execute the display() method of the passed object
void execute(Base &obj) { // this is a reference to the base class object.
    obj.display(); // Calls the display() method of the actual object type (due to virtual function)
}

int main() {
    Base b; // Create an object of the Base class
    Derived d; // Create an object of the Derived class

    execute(b); // Calls Base::display() because b is a Base object
    execute(d); // Calls Derived::display() because d is a Derived object

    // what's happening here is that the base class object is being passed to the function execute.
    // the function execute is taking the base class object as reference.
    // the function execute is calling the display function of the base class object.

    return 0;
}