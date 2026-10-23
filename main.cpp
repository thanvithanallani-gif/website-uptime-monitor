#include <iostream>
#include <string>
#include "response_time.h"
#include "uptime.h"
#include "history.h"

using namespace std;

int main() {
    int choice;

    int totalChecks = 0;
    int successfulChecks = 0;

    do {
        cout << "\n===== WEBSITE UPTIME MONITOR =====\n";
        cout << "1. Check Website Status\n";
        cout << "2. View Monitoring History\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter 1, 2, or 3.\n";
            continue;
        }

        if (choice == 1) {
            string url;
            double milliseconds = 0.0;
            int httpCode = 0;

            cout << "Enter website URL: ";
            cin >> url;

            bool success =
                measureResponseTime(url, milliseconds, httpCode);

            totalChecks++;

            string status;

            if (success) {
                successfulChecks++;
                status = "UP";

                cout << "\nWebsite Status: UP\n";
                cout << "HTTP Code: " << httpCode << "\n";
                cout << "Response Time: "
                     << milliseconds << " ms\n";
            } else {
                status = "DOWN";

                cout << "\nWebsite Status: DOWN or request failed.\n";
            }

            double uptime = calculateUptimePercentage(
                totalChecks, successfulChecks
            );

            cout << "Uptime (this session): "
                 << uptime << "%\n";

            saveHistory(url, status, milliseconds);
        }
        else if (choice == 2) {
            viewHistory();
        }
        else if (choice == 3) {
            cout << "Exiting Website Uptime Monitor.\n";
        }
        else {
            cout << "Invalid choice. Please select 1, 2, or 3.\n";
        }

    } while (choice != 3);

    return 0;
}