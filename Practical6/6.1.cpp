#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter stack size: ";
    cin >> n;

    int stack[100];
    int top = -1;
    int operations;
    
    cout << "Enter number of operations: ";
    cin >> operations;

    for (int i = 0; i < operations; i++) {
        int choice, value;

        cout << "\n1. Place tray (Push)";
        cout << "\n2. Take tray (Pop)";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter tray number:";
            cin >> value;

            if (top == n - 1) {
                cout << "Error: Stack is full." << endl;
            } else {
                top++;
                stack[top] = value;
                cout << "Top tray:" << stack[top] << endl;
            }
        }
        else if (choice == 2) {
            if (top == -1) {
                cout << "Error: Stack is empty." << endl;
            } else {
                cout << "Removed tray:" << stack[top] << endl;
                top--;

                if (top != -1)
                    cout << "Top tray:" << stack[top] << endl;
                else
                    cout << "Stack is empty." << endl;
            }
        }
    }

    return 0;
}