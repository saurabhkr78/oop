/*
-used to acheive runtime polymorphism
-when a function is declared as virtual in a base class, it is redefined in the derived class
-vf cannot be static
-vf cannot be a friend function
-vf should be used using pointers or references of base class type to achieve runtime polymorphism
-it's not mandatory for derived class to override the virtual function.
-always defined in base class

-IF WE DONT REDEFINE THE FUNCTION IN DERIVED CLASS THEN BASE CLASS FUNCTION WILL BE CALLED

*/


// #include<bits/stdc++.h>
// using namespace std;

// class Parernt{
//     public:
//     virtual void print(){
//         cout<<"Parent"<<endl;
//     }
// };
// class Child:public Parernt{
//     public:
//     void print(){
//         cout<<"Child"<<endl;
//     }
// };


// int main()
// {
//     Parernt *p;//always use pointer or reference of base class
//     Child c;
//     p=&c;
//     p->print();
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;

// class Parernt{
//     public:
//     virtual void print();
        
    
// };
// class Child:public Parernt{
//     public:
//     void print(){
//         cout<<"Child"<<endl;
//     }
// };


// int main()
// {
//     Parernt *p;//always use pointer or reference of base class
//     Child c;
//     p=&c;
//     p->print();
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

class Parernt{
    public:
    virtual void print(){
        cout<<"Parent"<<endl;
    }
};
class Child:public Parernt{};


int main()
{
    Parernt *p;//always use pointer or reference of base class
    Child c;
    p=&c;
    p->print();
    return 0;
}