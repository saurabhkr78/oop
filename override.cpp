/*
--if we need to override a function in the derived class, we need to use the keyword 'override' in the derived class.
--if we don't use the keyword 'override' in the derived class, the base class function will be called.
--if we use the keyword 'override' in the derived class, and the function is not overridden in the derived class, the compiler will throw an error.
--when we need to implement our own defintion to a virtual function which is defined in the base class, we need to use the keyword 'override' in the derived class.
--implementation tells us that parent class has already provided the implementation of the function and we are just overriding it.

*/

#include<bits/stdc++.h>
using namespace std;    

class Strategy {
public:
    int order_qnty;
    virtual void modifyStrategy(int qnty) {
        order_qnty = qnty;
    }



};
class SubStrategy : public Strategy {
public:
    void modifyStrategy(int qnty) override {
        order_qnty = qnty;
    }
    void createStrategy() {
        cout << "SubStrategy" << endl;
    }
};