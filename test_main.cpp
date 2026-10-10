#include <iostream>
#include <chrono>
#include "response_time.h"
#include "uptime.h"
int main() {
    using namespace std::chrono;
    auto start = steady_clock::now();
    auto end = start + milliseconds(250);
    double responseTime =
        calculateResponseTimeMs(start, end);
    std::cout << "Response Time: "
              << responseTime << " ms\n";
    double uptime =
        calculateUptimePercentage(95, 100);
    std::cout << "Uptime: " << uptime << "%\n";
    return 0;
}
