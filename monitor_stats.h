#ifndef MONITOR_STATS_H
#define MONITOR_STATS_H

struct MonitorStats {
    int totalChecks = 0;
    int successfulChecks = 0;
    int failedChecks = 0;
};

inline void recordCheck(
    MonitorStats& stats,
    bool isSuccessful
) {
    stats.totalChecks++;

    if (isSuccessful) {
        stats.successfulChecks++;
    }
    else {
        stats.failedChecks++;
    }
}

inline double calculateSuccessRate(
    const MonitorStats& stats
) {
    if (stats.totalChecks == 0) {
        return 0.0;
    }

    return (static_cast<double>(stats.successfulChecks)
            / stats.totalChecks) * 100.0;
}

#endif
