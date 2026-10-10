
#ifndef UPTIME_H
#define UPTIME_H

inline double calculateUptimePercentage(
    int successfulChecks,
    int totalChecks
) {
    if (totalChecks <= 0 ||
        successfulChecks < 0 ||
        successfulChecks > totalChecks) {
        return 0.0;
    }

    return (static_cast<double>(successfulChecks)
            / totalChecks) * 100.0;
}

#endif
