
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include "response_time.h"
#include "uptime.h"
#include "history.h"

using namespace std;

int main() {
    int choice;

    do {
        cout << "\n===== WEEK 3 WEBSITE UPTIME MONITOR =====\n";
        cout << "1. Check Website\n";
        cout << "2. View Monitoring History\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            return 1;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            string url;
            int checks;

            cout << "Enter website URL: ";
            getline(cin, url);

            cout << "How many times to check? ";
            if (!(cin >> checks) || checks <= 0) {
                cout << "Enter a valid positive number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int successfulChecks = 0;
            int failedChecks = 0;
            double totalResponseTime = 0.0;
            double minResponseTime = numeric_limits<double>::max();
            double maxResponseTime = 0.0;

            for (int i = 1; i <= checks; i++) {
                double milliseconds = 0.0;
                int httpCode = 0;

                cout << "\nCheck " << i << ":\n";

                bool success =
                    measureResponseTime(url, milliseconds, httpCode);

                if (success) {
                    successfulChecks++;
                    totalResponseTime += milliseconds;

                    if (milliseconds < minResponseTime)
                        minResponseTime = milliseconds;

                    if (milliseconds > maxResponseTime)
                        maxResponseTime = milliseconds;

                    cout << "Status: UP\n";
                    cout << "HTTP Code: " << httpCode << '\n';
                    saveHistory(url, "UP", milliseconds);
                } else {
                    failedChecks++;
                    cout << "Status: DOWN\n";
                    cout << "HTTP Code: " << httpCode << '\n';
                    saveHistory(url, "DOWN", milliseconds);
                }

                cout << fixed << setprecision(2);
                cout << "Response Time: " << milliseconds << " ms\n";
            }

            double uptime =
                calculateUptimePercentage(successfulChecks, checks);

            cout << "\n===== WEEK 3 SUMMARY =====\n";
            cout << "Total Checks: " << checks << '\n';
            cout << "Successful Checks: " << successfulChecks << '\n';
            cout << "Failed Checks: " << failedChecks << '\n';
            cout << fixed << setprecision(2);
            cout << "Uptime: " << uptime << "%\n";

            if (successfulChecks > 0) {
                cout << "Average Response Time: "
                     << totalResponseTime / successfulChecks << " ms\n";
                cout << "Minimum Response Time: "
                     << minResponseTime << " ms\n";
                cout << "Maximum Response Time: "
                     << maxResponseTime << " ms\n";
            } else {
                cout << "No successful checks; response-time statistics unavailable.\n";
            }
        }
        else if (choice == 2) {
            viewHistory();
        }
        else if (choice != 3) {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    cout << "Exiting monitor.\n";
    return 0;
}
