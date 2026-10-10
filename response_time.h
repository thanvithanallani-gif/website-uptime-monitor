#include<string>
#ifndef RESPONSE_TIME_H
#define RESPONSE_TIME_H

#include <chrono>

double calculateResponseTimeMs(
    std::chrono::steady_clock::time_point start,
    std::chrono::steady_clock::time_point end
);
bool measureResponseTime(
    const std::string& url,
    double& milliseconds,
    int& httpCode
);
#endif
