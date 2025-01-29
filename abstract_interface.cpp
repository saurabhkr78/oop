/*
--with the help of abstract class, we can implement the interface in C++.
--with the help of interface we can create an appropriate base class with the help of that base class we can create mulptiple derived classes.
--interface in C++ is implemented using abstract class.
--interface is a class which work as a base class for child classes.
--if inside a class, a function is declared as pure virtual function, then the class is called abstract class.
--because our abstract class is not providing the implementation of the pure virtual function. sop, we cannot create the object of the abstract class.
--we can only create the object of the derived class.
--each class can have their own implementation of the pure virtual function.
*/


/*

#include<bits/stdc++.h>
using namespace std;

class Strategy{
    public:
    virtual void submitOrder()=0;
};
class Strategy1:public Strategy{
    public:
    void submitOrder(){
        cout<<"Strategy1"<<endl;
    }
};
class Strategy2:public Strategy{
    public:
    void submitOrder(){
        cout<<"Strategy2"<<endl;
    }
};
*/

/*
--if we have a normal virtaul function in the base class, then we can provide the implementation of the function in the base class itself.
--A base class pointer can point to objects of derived classes.
--A pointer of the base class type (Strategy*) can point to objects of derived classes (Strategy1, Strategy2).

---When you call a virtual method through the base class pointer, the derived class's implementation is executed (if it exists).

class Strategy{
    public:
    virtual void submitOrder()=0;
    vitual void modifyOrder(){
        cout<<"Modify Order"<<endl;
    }
};
class Strategy1:public Strategy{
    public:
    void submitOrder(){
        cout<<"Strategy1"<<endl;
    }
    void modifyOrder(){
        cout<<"Modify Order Strategy1"<<endl;
    }
};
class Strategy2:public Strategy{
    public:
    void submitOrder(){
        cout<<"Strategy2"<<endl;
    }
    void modifyOrder(){
        cout<<"Modify Order Strategy2"<<endl;
    }
};

int main(){
    Strategy*s;
    Strategy1 s1;
    Strategy2 s2;
    s=&s1;
    s->submitOrder();
    s->modifyOrder();
    s=&s2;
    s->submitOrder();
    s->modifyOrder();

    return 0;

}
*/