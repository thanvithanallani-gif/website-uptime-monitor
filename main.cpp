#include <iostream>
#include<string>
#include<chrono>
#include"response_time.h"
#include"uptime.h"
using namespace std;

int main() {
    int choice;
    int totalChecks = 0;
    int successfulChecks = 0;
    cout << "\n===== WEBSITE UPTIME MONITOR =====\n";

    cout << "1. Check Website Status\n";
    cout << "2. View Monitoring History\n";
    cout << "3. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
    
    string url;
    double milliseconds = 0.0;
    int httpCode = 0;

    cout << "Enter website URL (e.g. https://example.com): ";
    cin >> url;

    bool success = measureResponseTime(url, milliseconds, httpCode);
    totalChecks++;

    if (success) {
        successfulChecks++;
    }
    if (success) {
        cout << "Website status: UP\n";
        cout << "HTTP Code: " << httpCode << "\n";
        cout << "Response Time: " << milliseconds << " ms\n";
    } else {
        cout << "Website status: DOWN or request failed.\n";
    }
    double uptime = calculateUptimePercentage(
     totalChecks, successfulChecks
);

cout << "Uptime: " << uptime << "%\n";
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