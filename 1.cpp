#include<bits/stdc++.h>
using namespace std;

class Strategy{
    public:
    int order_qty;
    int limit_price;
    int account_id;
    string account_name;

    Strategy(int order_qty,int limit_price,int account_id,string account_name){
        this->order_qty=order_qty;
        this->limit_price=limit_price;
        this->account_id=account_id;
        this->account_name=account_name;
    }

    void print(){
        cout<<order_qty<<endl;
        cout<<limit_price<<endl;
        cout<<account_id<<endl;
        cout<<account_name<<endl;

    }
};
int main(){
    Strategy obj(1,2,3,"saurabh");
    obj.print();
}