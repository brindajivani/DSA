
#include <iostream>
using namespace std;

int main() {
    int parking[10] = {0};
    int n, reg;

    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter registration number: ";
        cin >> reg;

        int slot = reg % 10;
        int count = 0;

        while (parking[slot] != 0 && count < 10) {
            slot = (slot + 1) % 10;
            count++;
        }

        if (count == 10) {
            cout << "Parking lot is full!\n";
        } else {
            parking[slot] = reg;
            cout << "Vehicle " << reg
                 << " parked at slot " << slot << endl;
        }
    }

    cout << "\nFinal Parking Slots:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";
        if (parking[i] == 0)
            cout << "Empty";
        else
            cout << parking[i];
        cout << endl;
    }

    return 0;
}
