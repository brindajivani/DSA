
#include <iostream>
using namespace std;

int main() {
    int table[10] = {0};
    int n, id;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter student ID: ";
        cin >> id;

        int h1 = id % 10;
        int h2 = 7 - (id % 7);
        int j = 0;

        while (j < 10) {
            int slot = (h1 + j * h2) % 10;

            if (table[slot] == 0) {
                table[slot] = id;
                cout << "Student " << id
                     << " placed at slot " << slot << endl;
                break;
            }

            j++;
        }

        if (j == 10) {
            cout << "No available slot for ID " << id << endl;
        }
    }

    cout << "\nFinal Hash Table:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";

        if (table[i] == 0)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }

    return 0;
}
