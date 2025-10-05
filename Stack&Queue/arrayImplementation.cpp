#include <iostream>
using namespace std;

class Stack {
    int sz;
    int top;
    int* arr;

public:
    Stack() {
        sz = 0;
        top = -1;
        arr = new int[100]; // fixed max size
    }

    void push(int val) {
        top++;
        arr[top] = val;
        sz++;
        cout << "Pushed: " << val << endl;
    }

    void pop() {
        if (top >= 0) {
            cout << "Popped: " << arr[top] << endl;
            top--;
            sz--;
        } else {
            cout << "Stack underflow!\n";
        }
    }

    int Top() {
        return (top > -1) ? arr[top] : 0;
    }

    bool empty() {
        return top == -1;
    }

    int size() {
        return sz;
    }

    ~Stack() {
        delete[] arr;
    }
};


int main() {

    Stack* st = new Stack();

    st->push(6); cout << "Top: " << cout<<"" <<st->Top() << endl;
    st->push(5); cout << "Top: " << st->Top() << endl;
    
    st->push(3); cout << "Top: " << st->Top() << endl;
    st->pop();   cout << "Top: " << st->Top() << endl;

    delete st;
    return 0;
}