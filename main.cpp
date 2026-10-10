

#include <iostream>
#include <string>
using namespace std;

// Function to validate website URL format
bool isValidURL(string url) {
    if (url.find("https://") == 0 ||
        url.find("http://") == 0) {
        return true;
    }
    return false;
}

// Function to check website URL
void checkWebsiteStatus() {
    string url;

    cout << "\nEnter website URL: ";
    cin >> url;

    if (isValidURL(url)) {
        cout << "URL format is valid.\n";
        cout << "Website: " << url << endl;
        cout << "Actual status checking is not implemented yet.\n";
    } else {
        cout << "Invalid URL format!\n";
        cout << "Use http:// or https:// at the beginning.\n";
    }
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n===== WEBSITE UPTIME MONITOR =====\n";
        cout << "1. Check Website Status\n";
        cout << "2. View Monitoring History\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        if (choice == 1) {
            checkWebsiteStatus();
        }
        else if (choice == 2) {
            cout << "Monitoring history selected.\n";
            cout << "History feature will be added next.\n";
        }
        else if (choice == 3) {
            cout << "Exiting program.\n";
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);
    return 0;
}
