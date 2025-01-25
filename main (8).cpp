#include <bits/stdc++.h>
using namespace std;

class Stack {
    int capacity;
    int top;
    int* arr;

public:
    Stack(int c) {
        capacity = c;
        arr = new int[c];
        top = -1;
    }
    ~Stack() {
        delete[] arr; 
    }
    void push(int data) {
        if (top == capacity - 1) {
            cout << "Overflow condition: Stack is full" << endl;
            return;
        }
        top++;
        arr[top] = data;
    }
    int pop() {
        if (top == -1) {
            cout << "Underflow condition: Stack is empty" << endl;
            return INT_MIN;
        }
        int ele = arr[top];
        top--;
        return ele;
    }
    int topElement() { 
        if (top == -1) {
            cout << "Underflow condition: Stack is empty" << endl;
            return INT_MIN;
        }
        return arr[top];
    }
    bool IsEmpty() {
        return top == -1;
    }
    int size() {
        return top + 1;
    }
    bool IsFull() {
        return top == capacity - 1;
    }
};

int main() {
    Stack obj(5);

    obj.push(1);
    obj.push(2);
    obj.push(3);

    cout << "Current size of the stack: " << obj.size() << endl;
    cout << "Top element: " << obj.topElement() << endl;
    cout << "Is the stack full? " << (obj.IsFull() ? "Yes" : "No") << endl;
    cout << "Is the stack empty? " << (obj.IsEmpty() ? "Yes" : "No") << endl;

    cout << "Popping the top element: " << obj.pop() << endl;
    obj.push(5);

    cout << "New top element: " << obj.topElement() << endl;
    cout << "Current size of the stack: " << obj.size() << endl;

    return 0;
}
