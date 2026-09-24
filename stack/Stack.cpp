#include <iostream>
using namespace std;

class Stack{
    private:
        int stack[5];
        int top;

    public:
        Stack() {
            top = -1;
        }

        void push(int value) {
            if(top == 4) {
                cout << "Stack Overflow";
                return;
            }

            stack[++top] = value;
        }

        void pop() {
            if (top == -1) {
                cout << "Stack Underflow" << endl;
                return;
            }

            top--;
        }

        int peek() {
            if (top == -1) {
                cout << "Stack is Empty" << endl;
                return -1;
            }

            return stack[top];
        }

        bool isEmpty() {
            return top == -1;
        }

        bool isFull() {
            return top ==4;
        }

        void displayAll() {
            if (top == -1) {
                cout << "Stack is Empty" << endl;
                return;
            }

            cout << "Stack elements: ";

            for (int i = top; i >=0; i--) {
                cout << stack[i] << " ";
            }

            cout << endl;
        }


};
