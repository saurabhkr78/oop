/*
--if we assigbn base class pointer the object of derived class
-- when we call destructor of base class pointer, the destructor of derived class will not be called.
-- so, we need to make the destructor of base class as virtual.
-- when we make the destructor of base class as virtual, the destructor of derived class will be called first and then the destructor of base class will be called.
--this will help in freeing the memory of the derived class object aswell as the base class object.


*/


#include<bits/stdc++.h>
using namespace std;

class Base{
public:
    Base(){
        cout<<"Base Constructor"<<endl;
    }
    virtual ~Base(){
        cout<<"Base Destructor"<<endl;
    }
};
class Derived1:public Base{
public:
    Derived1(){
        cout<<"Derived1 Constructor"<<endl;
    }
    ~Derived1(){
        cout<<"Derived1 Destructor"<<endl;
    }
};
class Derived2:public Base{
public:
    Derived2(){
        cout<<"Derived2 Constructor"<<endl;
    }
    ~Derived2(){
        cout<<"Derived2 Destructor"<<endl;
    }
};

int main(){
    Base *b=new Derived1();
    delete b;
    cout<<endl;
    b=new Derived2();
    delete b;
    return 0;
}