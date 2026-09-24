#include <iostream>
using namespace std;

class Queue {
private:
    const static int SIZE = 5;

    int array[SIZE];
    int start;
    int end;
    int count;

public:
    Queue() {
        start = 0;
        end = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == SIZE;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }

        end = (end + 1) % SIZE;
        array[end] = value;
        count++;

        cout << value << " enqueued." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }

        cout << array[start] << " dequeued." << endl;

        start = (start + 1) % SIZE;
        count--;
    }

    void displayAll() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue: ";

        for (int i = 0; i < count; i++) {
            int index = (start + i) % SIZE;
            cout << array[index] << " ";
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    // Fill the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.displayAll();

    // Remove two elements
    q.dequeue();
    q.dequeue();

    q.displayAll();

    // These operations cause end to reach index 4
    q.enqueue(50);

    // This operation causes end to wrap from index 4 to index 0
    q.enqueue(60);

    q.displayAll();

    return 0;
}