#include <iostream>
using namespace std;

struct Node {
    int ticketID;
    int priority;

    Node* next;
    Node* prev;
};
Node* head = nullptr;
Node* tail = nullptr;
Node* current = nullptr;

int ticketCount = 0;
long long totalLinkModifications = 0;

Node* findTicket(int id) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->ticketID == id) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}
void newTicket(int id, int priority) {
    int linkModifications = 0;
    if (priority < 1 || priority > 5) {
        cout << "Invalid priority. Priority must be 1 to 5.\n";
        return;
    }
    if (findTicket(id) != nullptr) {
        cout << "Ticket ID already exists.\n";
        return;
    }
    Node* newNode = new Node;
    newNode->ticketID = id;
    newNode->priority = priority;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        current = newNode;
        ticketCount++;
    }
    else if (priority > head->priority) {
        newNode->next = head;
        linkModifications++;
        head->prev = newNode;
        linkModifications++;
        head = newNode;
        ticketCount++;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr &&
               temp->next->priority >= priority) {

            temp = temp->next;
        }
        Node* nextNode = temp->next;
        newNode->prev = temp;
        linkModifications++;
        newNode->next = nextNode;
        linkModifications++;
        temp->next = newNode;
        linkModifications++;
        if (nextNode != nullptr) {
            nextNode->prev = newNode;
            linkModifications++;
        }
        else {
            tail = newNode;
        }
        ticketCount++;
    }
    totalLinkModifications += linkModifications;
    cout << "Ticket " << id << " added.\n";
    cout << "Link modifications: "
         << linkModifications << endl;
}
void nextTicket() {
    if (current == nullptr) {
        cout << "No active tickets.\n";
        return;
    }
    if (current->next == nullptr) {
        cout << "Already at the last ticket.\n";
        return;
    }
    current = current->next;
    cout << "Current ticket: "
         << current->ticketID << endl;
}
void previousTicket() {
    if (current == nullptr) {
        cout << "No active tickets.\n";
        return;
    }
    if (current->prev == nullptr) {
        cout << "Already at the first ticket.\n";
        return;
    }
    current = current->prev;
    cout << "Current ticket: "
         << current->ticketID << endl;
}
void resolveTicket(int id) {
    int linkModifications = 0;
    Node* target = findTicket(id);
    if (target == nullptr) {
        cout << "Ticket Not Found.\n";
        return;
    }
    if (target == head && target == tail) {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
        ticketCount--;
    }
    else if (target == head) {
        head = target->next;
        head->prev = nullptr;
        linkModifications++;
        if (current == target) {
            current = head;
        }
        ticketCount--;
    }
    else if (target == tail) {
        tail = target->prev;
        tail->next = nullptr;
        linkModifications++;
        if (current == target) {
            current = tail;
        }
        ticketCount--;
    }
    else {
        Node* previousNode = target->prev;
        Node* nextNode = target->next;
        previousNode->next = nextNode;
        linkModifications++;
        nextNode->prev = previousNode;
        linkModifications++;
        if (current == target) {
            current = nextNode;
        }
        ticketCount--;
    }
    delete target;
    totalLinkModifications += linkModifications;
    cout << "Ticket " << id << " resolved.\n";
    cout << "Link modifications: "
         << linkModifications << endl;
}
void changePriority(int id, int newPriority) {
    int linkModifications = 0;
    if (newPriority < 1 || newPriority > 5) {
        cout << "Invalid priority. Priority must be 1 to 5.\n";
        return;
    }
    Node* target = findTicket(id);
    if (target == nullptr) {
        cout << "Ticket Not Found.\n";
        return;
    }
    if (target->priority == newPriority) {
        cout << "Priority unchanged.\n";
        cout << "Link modifications: 0\n";
        return;
    }
    bool wasCurrent = (current == target);
    if (target == head && target == tail) {
        head = nullptr;
        tail = nullptr;
    }
    else if (target == head) {
        head = target->next;
        head->prev = nullptr;
        linkModifications++;
    }
    else if (target == tail) {
        tail = target->prev;
        tail->next = nullptr;
        linkModifications++;
    }
    else {
        Node* previousNode = target->prev;
        Node* nextNode = target->next;
        previousNode->next = nextNode;
        linkModifications++;
        nextNode->prev = previousNode;
        linkModifications++;
    }
    target->priority = newPriority;
    target->next = nullptr;
    target->prev = nullptr;
    if (head == nullptr) {
        head = target;
        tail = target;
    }
    else if (newPriority > head->priority) {
        target->next = head;
        linkModifications++;
        head->prev = target;
        linkModifications++;
        head = target;
    }
    else {

        Node* temp = head;

        while (temp->next != nullptr &&
               temp->next->priority >= newPriority) {

            temp = temp->next;
        }
        Node* nextNode = temp->next;
        target->prev = temp;
        linkModifications++;
        target->next = nextNode;
        linkModifications++;
        temp->next = target;
        linkModifications++;
        if (nextNode != nullptr) {
            nextNode->prev = target;
            linkModifications++;
        }
        else {
            tail = target;
        }
    }
    if (wasCurrent) {
        current = target;
    }
    totalLinkModifications += linkModifications;
    cout << "Priority changed for Ticket "
         << id << ".\n";
    cout << "New Priority: "
         << newPriority << endl;
    cout << "Link modifications: "
         << linkModifications << endl;
}
void show() {
    if (head == nullptr) {
        cout << "No active tickets.\n";
        return;
    }
    cout << "\nActive Tickets:\n";
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Ticket ID: "
             << temp->ticketID
             << "  Priority: "
             << temp->priority << endl;
        temp = temp->next;
    }
}
void showReverse() {
    if (tail == nullptr) {
        cout << "No active tickets.\n";
        return;
    }
    cout << "\nTickets in Reverse Order:\n";
    Node* temp = tail;
    while (temp != nullptr) {
        cout << "Ticket ID: "
             << temp->ticketID
             << "  Priority: "
             << temp->priority << endl;
        temp = temp->prev;
    }
}
void showCurrent() {
    if (current == nullptr) {
        cout << "No ticket is currently selected.\n";
        return;
    }
    cout << "Current Ticket ID: "
         << current->ticketID << endl;
    cout << "Priority: "
         << current->priority << endl;
}
int main() {
    string command;
    cout << "TECHNICAL SUPPORT TICKET NAVIGATOR:\n";
    cout << "\nCommands:\n";
    cout << "NEW id priority\n";
    cout << "NEXT\n";
    cout << "PREVIOUS\n";
    cout << "RESOLVE id\n";
    cout << "CHANGE id newPriority\n";
    cout << "SHOW\n";
    cout << "SHOW_REVERSE\n";
    cout << "CURRENT\n";
    cout << "EXIT\n";
    while (true) {
        cout << "\nEnter command: ";
        cin >> command;
        if (command == "NEW") {

            int id, priority;

            cin >> id >> priority;

            newTicket(id, priority);
        }
        else if (command == "NEXT") {

            nextTicket();
        }
        else if (command == "PREVIOUS") {

            previousTicket();
        }
        else if (command == "RESOLVE") {

            int id;

            cin >> id;

            resolveTicket(id);
        }
        else if (command == "CHANGE") {

            int id, priority;

            cin >> id >> priority;

            changePriority(id, priority);
        }
        else if (command == "SHOW") {

            show();
        }
        else if (command == "SHOW_REVERSE") {

            showReverse();
        }
        else if (command == "CURRENT") {
            showCurrent();
        }
        else if (command == "EXIT") {
            cout << "\nTotal link modifications: "
                 << totalLinkModifications << endl;
            cout << "Program terminated.\n";
            break;
        }
        else {
            cout << "Invalid command.\n";
        }
    }
    Node* temp = head;
    while (temp != nullptr) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    return 0;
}