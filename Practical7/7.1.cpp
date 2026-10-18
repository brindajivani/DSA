#include <iostream>
using namespace std;

class Queue {
    int arr[5];
    int front, rear;
    int size;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    // Join queue
    void join(int token) {
        if (size == 5) {
            cout << "Error: Queue is full. Token "
                 << token << " cannot be issued." << endl;
            return;
        }

        rear = (rear + 1) % 5;
        arr[rear] = token;
        size++;

        cout << "Joined Token: " << token << endl;
        printFront();
    }

    // Serve visitor
    void serve() {
        if (size == 0) {
            cout << "Error: Queue is empty. Nobody to serve."
                 << endl;
            return;
        }

        cout << "Served Token: " << arr[front] << endl;

        front = (front + 1) % 5;
        size--;

        if (size > 0)
            printFront();
        else
            cout << "Queue is empty." << endl;
    }

    // Print current front
    void printFront() {
        cout << "Current Front Token: "
             << arr[front] << endl;
    }
};

int main() {

    Queue q;

    q.join(101);
    q.join(102);
    q.join(103);

    q.serve();

    q.join(104);
    q.join(105);
    q.join(106);

    q.serve();
    q.serve();

    q.join(107);

    return 0;
}