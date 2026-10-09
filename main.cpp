#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "\n===== WEBSITE UPTIME MONITOR =====\n";

    cout << "1. Check Website Status\n";
    cout << "2. View Monitoring History\n";
    cout << "3. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Website status checking selected.\n";
    }
    else if (choice == 2) {
        cout << "Monitoring history selected.\n";
    }
    else if (choice == 3) {
        cout << "Exiting program.\n";
    }
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}