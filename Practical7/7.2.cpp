#include <iostream>
#include <string>
using namespace std;

struct Node {
    int patient;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Patient arrives
    void arrive(int patient) {
        Node* newNode = new Node();

        newNode->patient = patient;
        newNode->next = NULL;

        // If queue is empty
        if (rear == NULL) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Patient " << patient << " arrived." << endl;
        printFront();
    }

    // Doctor attends patient
    void attend() {

        // Queue is empty
        if (front == NULL) {
            cout << "Error: No patients waiting." << endl;
            return;
        }

        Node* temp = front;

        cout << "Patient " << front->patient
             << " attended." << endl;

        front = front->next;

        // If queue becomes empty
        if (front == NULL) {
            rear = NULL;
        }

        delete temp;

        if (front != NULL)
            printFront();
        else
            cout << "Ward is empty." << endl;
    }

    // Display current front patient
    void printFront() {
        cout << "Current Front Patient: "
             << front->patient << endl;
    }
};

int main() {

    Queue q;

    q.arrive(101);
    q.arrive(102);
    q.arrive(103);

    q.attend();
    q.attend();

    q.arrive(104);

    q.attend();
    q.attend();

    // Try to attend when empty
    q.attend();

    return 0;
}