
#include <iostream>
#include <string>
#include <iomanip>
#include "response_time.h"
#include "uptime.h"

using namespace std;

int main() {
    string url;
    int numberOfChecks;

    cout << "===== WEEK 2 WEBSITE MONITOR =====\n";
    cout << "Enter website URL: ";
    cin >> url;

    cout << "Enter number of checks: ";
    cin >> numberOfChecks;

    if (numberOfChecks <= 0) {
        cout << "Please enter a positive number.\n";
        return 1;
    }

    int totalChecks = 0;
    int successfulChecks = 0;
    double totalResponseTime = 0.0;

    for (int i = 1; i <= numberOfChecks; i++) {
        double milliseconds = 0.0;
        int httpCode = 0;

        cout << "\nCheck " << i << ":\n";

        bool success =
            measureResponseTime(url, milliseconds, httpCode);

        totalChecks++;

        if (success) {
            successfulChecks++;
            totalResponseTime += milliseconds;

            cout << "Status: UP\n";
            cout << "HTTP Code: " << httpCode << "\n";
            cout << fixed << setprecision(2);
            cout << "Response Time: "
                 << milliseconds << " ms\n";
        } else {
            cout << "Status: DOWN or request failed\n";
            cout << "HTTP Code: " << httpCode << "\n";
        }
    }

    int failedChecks = totalChecks - successfulChecks;

    double uptime =
        calculateUptimePercentage(successfulChecks, totalChecks);

    cout << "\n===== WEEK 2 SUMMARY =====\n";
    cout << "Total Checks: " << totalChecks << "\n";
    cout << "Successful Checks: " << successfulChecks << "\n";
    cout << "Failed Checks: " << failedChecks << "\n";

    cout << fixed << setprecision(2);
    cout << "Uptime: " << uptime << "%\n";

    if (successfulChecks > 0) {
        cout << "Average Response Time: "
             << totalResponseTime / successfulChecks
             << " ms\n";
    } else {
        cout << "Average Response Time: N/A\n";
    }

    return 0;
}
