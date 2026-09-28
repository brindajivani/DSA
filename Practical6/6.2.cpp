#include <iostream>
using namespace std;

struct Node {
    string page;
    Node* next;
};

int main() {
    Node* top = NULL;

    int operations;
    cout << "Enter number of operations:";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        int choice;
        string page;

        cout << "\n1. Visit page";
        cout << "\n2. Back";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter page name: ";
            cin >> page;

            Node* newNode = new Node();
            newNode->page = page;
            newNode->next = top;
            top = newNode;

            cout << "Current page: " << top->page << endl;
        }
        else if (choice == 2) {
            if (top == NULL) {
                cout << "No history available." << endl;
            } else {
                Node* temp = top;
                top = top->next;

                delete temp;

                if (top != NULL)
                    cout << "Current page: " << top->page << endl;
                else
                    cout << "No page in history." << endl;
            }
        }
    }

    return 0;
}