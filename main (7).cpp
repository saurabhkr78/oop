#include <bits/stdc++.h>
using namespace std;

class OrderBuilder {
    public:
    int exchange_id;
    string exchange_name;

    OrderBuilder(int id, string name) {
        exchange_id = id;
        exchange_name = name;
    }
};

class Strategy {
    double order_quantity, price;
    string user_name;
    OrderBuilder* ob;

    public:
    Strategy(double qnt, double prc, string name) {
        order_quantity = qnt;
        price = prc;
        user_name = name;

        OrderBuilder* obj = new OrderBuilder(100, "NSE");
        ob = obj;
    }
    //deep copy constructir
    Strategy(const Strategy& obj){//it receives class obj as args
        cout<<"Custom copy constructor called"<<endl;
        order_quantity=obj.order_quantity;
        price=obj.price;
        user_name=obj.user_name;
        
        ob=new OrderBuilder(*obj.ob);
    }

    ~Strategy() {
        cout << "Destructor Called obj deleted" << endl;
        delete ob; // Ensures dynamically allocated memory is released.
    }

    void print() {
        cout << "Order Quantity: " << order_quantity << endl;
        cout << "Price: " << price << endl;
        cout << "User Name: " << user_name << endl;
        cout << "Exchange Name: " << ob->exchange_name << endl;
    }
};

int main() {

    Strategy obj1 = Strategy(10, 10000, "Saurabh");
    obj1.print();
    Strategy obj2=obj1;
    obj2.print();
    Strategy obj3=Strategy(20,20000,"Isha");
    obj3.print();
    obj2=obj3;
    obj2.print();
    

   

    return 0;
}


