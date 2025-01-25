
#include <bits/stdc++.h>
using namespace std;

class Strategy{
    private:
    double order_quantity;
    double price;
    string name;
    
    public:
    void printmembers(const Strategy& obj){
        cout<<"order_quantity:"<<order_quantity<<endl;
        cout<<"price:"<<price<<endl;
        cout<<"name:"<<name<<endl;
    }
    Strategy(double order_quantity,double price,string name){
        this->order_quantity=order_quantity;
        this->price=price;
        this->name=name;
    }
    
};




int main()
{
    Strategy obj(13,13000,"saurabh");
    //so constructor can access privcate data members of class
    obj.printmembers(obj);

    return 0;
}