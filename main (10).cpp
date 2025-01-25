/*
this is a special pointer to an object. which is calling the member function.it is implicitly passed to all the member function.

-static member function are not the part of the object.
-you cannot explicitly tell this keyword to point on some other obj so this is a constant keyword;
-helps in differntiate between member variable and parameter/local variable with same name.
-this return object itself

*/

#include <iostream>
using namespace std;

class Demo {
public:
    int value;

    Demo(int val) : value(val) {}

    void showValue() {
        cout << "Value using this pointer: " << this->value << endl;
    }
};

int main() {
    Demo obj(10);
    obj.showValue(); // `this` pointer is implicitly passed to showValue()
    return 0;
}


#include <iostream>
using namespace std;

class Demo {
public:
    static int staticValue;

    // Static member function
    static void showStaticValue() {
        cout << "Static Value: " << staticValue << endl;
        // cout << this->staticValue; // Error: `this` cannot be used in static functions
    }
};

int Demo::staticValue = 100; // Initialize static member

int main() {
    Demo::showStaticValue(); // Call static member function
    return 0;
}


#include <iostream>
using namespace std;

class Demo {
public:
    int value;

    Demo(int val) : value(val) {}

    void invalidOperation() {
        // this = nullptr; // Error: Assignment to `this` is not allowed
    }
};


#include <iostream>
using namespace std;

class Demo {
public:
    int value;

    Demo(int value) { // Parameter name is the same as the member variable name
        this->value = value; // Use `this` to refer to the member variable
    }

    void showValue() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Demo obj(20);
    obj.showValue();
    return 0;
}


#include <iostream>
using namespace std;

class Demo {
public:
    int value;

    Demo(int val) : value(val) {}

    Demo& setValue(int val) {
        this->value = val; // Modify the current object's value
        return *this;      // Return the current object
    }

    void showValue() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Demo obj(10);
    obj.setValue(30).showValue(); // Chaining function calls using `this`
    return 0;
}



#include <iostream>
using namespace std;

class Strategy;

class X {
public:
    void fun1(Strategy& s) {
        cout << "Accessing Strategy's ord_qnt: " << s.ord_qnt << endl;
    }
};

class Strategy {
private:
    double ord_qnt;

public:
    // Constructor to initialize ord_qnt
    Strategy(double order) : ord_qnt(order) {}

    void fun(X* x) {
        x->fun1(*this); // Passing *this (current object) to X's fun1()
    }
};

int main() {
    X xObj;                  // Create an object of class X
    Strategy sObj(100.50);    // Create an object of class Strategy

    sObj.fun(&xObj);          // Call fun method in Strategy, passing address of xObj

    return 0;
}
