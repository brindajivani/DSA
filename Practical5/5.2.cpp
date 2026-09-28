#include <iostream>
using namespace std;

//Singly Circular Linked List
struct SNode {
    int data;
    SNode* next;
};

SNode* shead = NULL;

void singlyInsert(int value, int position) {
    SNode* newNode = new SNode();
    newNode->data = value;

    if (shead == NULL) {
        shead = newNode;
        newNode->next = shead;
        return;
    }

    if (position == 1) {
        SNode* temp = shead;

        while (temp->next != shead)
            temp = temp->next;

        newNode->next = shead;
        temp->next = newNode;
        shead = newNode;
        return;
    }

    SNode* temp = shead;

    for (int i = 1; i < position - 1 && temp->next != shead; i++)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void singlyDelete(int value) {
    if (shead == NULL)
        return;

    if (shead->data == value && shead->next == shead) {
        delete shead;
        shead = NULL;
        return;
    }

    if (shead->data == value) {
        SNode* temp = shead;

        while (temp->next != shead)
            temp = temp->next;

        temp->next = shead->next;

        SNode* del = shead;
        shead = shead->next;
        delete del;
        return;
    }

    SNode* temp = shead;

    while (temp->next != shead &&
           temp->next->data != value)
        temp = temp->next;

    if (temp->next != shead) {
        SNode* del = temp->next;
        temp->next = del->next;
        delete del;
    }
}

void singlyDisplay() {
    if (shead == NULL) {
        cout << "Circle is empty." << endl;
        return;
    }

    SNode* temp = shead;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != shead);

    cout << endl;
}

//Doubly Circular Linked List
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

DNode* dhead = NULL;

void doublyInsert(int value, int position) {
    DNode* newNode = new DNode();
    newNode->data = value;

    if (dhead == NULL) {
        dhead = newNode;
        newNode->next = dhead;
        newNode->prev = dhead;
        return;
    }

    if (position == 1) {
        DNode* last = dhead->prev;

        newNode->next = dhead;
        newNode->prev = last;

        last->next = newNode;
        dhead->prev = newNode;

        dhead = newNode;
        return;
    }

    DNode* temp = dhead;

    for (int i = 1; i < position - 1 && temp->next != dhead; i++)
        temp = temp->next;

    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

void doublyDelete(int value) {
    if (dhead == NULL)
        return;

    DNode* temp = dhead;

    do {
        if (temp->data == value)
            break;

        temp = temp->next;
    } while (temp != dhead);

    if (temp->data != value)
        return;

    if (temp->next == temp) {
        delete temp;
        dhead = NULL;
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == dhead)
        dhead = temp->next;

    delete temp;
}

void doublyDisplay() {
    if (dhead == NULL) {
        cout << "Circle is empty." << endl;
        return;
    }

    DNode* temp = dhead;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != dhead);

    cout << endl;
}

int main() {

    int choice;
    int operation;
    int value;
    int position;

    cout << "Choose Circular Linked List:" << endl;
    cout << "1. Singly Circular Linked List" << endl;
    cout << "2. Doubly Circular Linked List" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    cout << "\nEnter number of operations: ";
    cin >> operation;

    for (int i = 0; i < operation; i++) {

        cout << "\n1. Join student";
        cout << "\n2. Leave student";
        cout << "\n3. Display circle";
        cout << "\nEnter operation: ";
        cin >> operation;

        if (operation == 1) {

            cout << "Enter student number: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            if (choice == 1) {
                singlyInsert(value, position);
                singlyDisplay();
            }
            else {
                doublyInsert(value, position);
                doublyDisplay();
            }
        }

        else if (operation == 2) {

            cout << "Enter student number to leave: ";
            cin >> value;

            if (choice == 1) {
                singlyDelete(value);
                singlyDisplay();
            }
            else {
                doublyDelete(value);
                doublyDisplay();
            }
        }

        else if (operation == 3) {

            if (choice == 1)
                singlyDisplay();
            else
                doublyDisplay();
        }
    }

    return 0;
}