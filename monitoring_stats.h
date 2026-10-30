#ifndef MONITORING_STATS_H
#define MONITORING_STATS_H

#include <iostream>
#include <iomanip>
using namespace std;

class MonitoringStats {
private:
    int totalChecks;
    int successfulChecks;
    int failedChecks;

public:
    MonitoringStats() {
        totalChecks = 0;
        successfulChecks = 0;
        failedChecks = 0;
    }

    void updateStats(string status) {
        totalChecks++;

        if (status == "UP") {
            successfulChecks++;
        }
        else {
            failedChecks++;
        }
    }

    double calculateUptime() const {
        if (totalChecks == 0)
            return 0.0;

        return (double)successfulChecks /
               totalChecks * 100.0;
    }

    void displayReport() const {
        cout << "\n===== MONITORING REPORT =====\n";

        cout << "Total Checks: " << totalChecks << endl;
        cout << "Successful Checks: "
             << successfulChecks << endl;
        cout << "Failed Checks: " << failedChecks << endl;

        cout << fixed << setprecision(2);
        cout << "Uptime Percentage: "
             << calculateUptime() << "%\n";
    }
};

#endif