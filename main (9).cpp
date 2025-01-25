/*
When we create an object statically, its memory gets allocated on the stack. 
As soon as the function (or the scope) in which the object is created ends, 
the destructor of the class is automatically called, and the memory for the object is released.

In this example:
1. The object `obj` is created in the `main` function, and memory is allocated for it on the stack.
2. When the `main` function exits, the destructor of the `Strategy` class is called automatically.
3. If the class contains dynamically allocated memory (like `order_qnt`), 
   the destructor should properly release it to avoid memory leaks.
*/

#include <bits/stdc++.h>
using namespace std;

class Strategy {
public:
    int* order_qnt;

    // Constructor with initialization
    Strategy(int order) : order_qnt(new int(order)) {
        cout << "Strategy class constructor is called. Order quantity: " << *order_qnt << endl;
    }

    void func() {
        cout << "This is a function of the Strategy class. Current order quantity: " << *order_qnt << endl;
    }

   
    ~Strategy() {
        delete order_qnt; // Release dynamically allocated memory
        cout << "Strategy class destructor is called. Memory released." << endl;
    }
};

int main() {
    Strategy obj(10);
    obj.func();

    // Destructor is automatically called when 'obj' goes out of scope
    return 0;
}




/*
When we dynamically create an object using `new`, the memory for the object is allocated on the heap. 
In such cases, the destructor is NOT called automatically when the pointer goes out of scope. 
Instead, we must explicitly release the memory by calling `delete` on the object.

In this example:
1. The `obj` pointer is created dynamically using `new`. 
   This allocates memory for the `Strategy` object on the heap.
2. The `func` method is called using the `obj` pointer, demonstrating the usage of the object.
3. Since `obj` is dynamically allocated, the destructor of the `Strategy` class will NOT be automatically called 
   when the program ends or when `obj` goes out of scope. This will result in a memory leak if `delete obj;` is not called.
4. To avoid a memory leak, the memory allocated for `obj` must be explicitly deallocated using `delete`.

Proper memory management is crucial when using `new` to dynamically allocate objects.
*/

#include <bits/stdc++.h>
using namespace std;

class Strategy {
public:
    int* order_qnt;

    // Constructor with initialization
    Strategy(int order) : order_qnt(new int(order)) {
        cout << "Strategy class constructor is called. Order quantity: " << *order_qnt << endl;
    }

    void func() {
        cout << "This is a function of the Strategy class. Current order quantity: " << *order_qnt << endl;
    }

    // Destructor to release memory
    ~Strategy() {
        delete order_qnt; // Release dynamically allocated memory
        cout << "Strategy class destructor is called. Memory released." << endl;
    }
};

int main() {
    Strategy* obj = new Strategy(10); // Dynamically allocate the object
    obj->func(); // Call member function

    // Explicitly delete the dynamically allocated object to release memory
    delete obj;

    return 0;
}
