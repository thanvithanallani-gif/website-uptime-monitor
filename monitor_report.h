
#ifndef MONITOR_REPORT_H
#define MONITOR_REPORT_H

#include <iostream>
#include <iomanip>

inline void displayMonitorReport(
    int totalChecks,
    int successfulChecks,
    int failedChecks
) {
    double successRate = 0.0;

    if (totalChecks > 0) {
        successRate =
            (static_cast<double>(successfulChecks)
             / totalChecks) * 100.0;
    }

    std::cout << "\n===== MONITORING REPORT =====\n";
    std::cout << "Total Checks: " << totalChecks << '\n';
    std::cout << "Successful Checks: "
              << successfulChecks << '\n';
    std::cout << "Failed Checks: "
              << failedChecks << '\n';

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Success Rate: "
              << successRate << "%\n";
}

#endif
