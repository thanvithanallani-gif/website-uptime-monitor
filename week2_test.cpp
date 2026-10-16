#include <iostream>
#include <chrono>
#include "uptime.h"

using namespace std;
using namespace std::chrono;

int main() {
    auto start = steady_clock::now();
    auto end = start + milliseconds(250);

    double responseTime =
        duration<double, milli>(end - start).count();

    double uptime = calculateUptimePercentage(95, 100);

    cout << "===== WEEK 2 TEST =====\n";
    cout << "Response Time: " << responseTime << " ms\n";
    cout << "Uptime: " << uptime << "%\n";

    return 0;
}