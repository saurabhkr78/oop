/*
we cannot provide definition of a pure virtual function in the parent class itself.
we need to provide the definition of the pure virtual function in the derived class.else compile time error will be thrown.



*/

#include<bits/stdc++.h>
using namespace std;
class Parent{
public:
    virtual void show()=0;
};
class Child:public Parent{ 
public:
    void show(){
        cout<<"Child"<<endl;
    }
};
class child2:public Parent{ 
public:
    void show(){
        cout<<"Child2"<<endl;
    }
};
