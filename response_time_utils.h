#ifndef RESPONSE_TIME_UTILS_H
#define RESPONSE_TIME_UTILS_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

inline string formatResponseTime(double ms) {
    stringstream ss;

    if (ms < 0)
        return "Invalid Response Time";

    if (ms >= 1000)
        ss << fixed << setprecision(2) << ms / 1000 << " seconds";
    else
        ss << fixed << setprecision(2) << ms << " ms";

    return ss.str();
}

#endif