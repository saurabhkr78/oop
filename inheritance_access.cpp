#include<bits/stdc++.h>
using namespace std;

class ParentStrategy {
public:
    int order_qnt;
    int price;

    ParentStrategy(int order_qnt, int price) : order_qnt(order_qnt), price(price) {};

    void printStrategy() {
        cout << order_qnt << endl;
        cout << price << endl;
    }

    void SubmitStrategy() {
        cout << "Parent Strategy Submitted" << endl;
    }

protected:
    void modifyStrategy() {
        cout << "Parent Strategy Modified" << endl;
    }

private:
    void cancelStrategy() {
        cout << "Parent Strategy Cancelled" << endl;
    }
};

class Strategy : public ParentStrategy {
public:
    Strategy(int order_qnt, int price) : ParentStrategy(order_qnt, price) {};

    void CreateStrategy() {
        cout << "Child Strategy Created" << endl;
        SubmitStrategy();  
        modifyStrategy();
        // cancelStrategy();  // This line won't work because cancelStrategy is private in ParentStrategy for that you need getter and setter function
    }
};

int main() {
    Strategy obj(1, 2);
    obj.printStrategy();
    obj.CreateStrategy();

    return 0;
}