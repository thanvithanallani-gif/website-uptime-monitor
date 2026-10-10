#include <iostream>
#include <string>
#include <chrono>
#include <cstdio>
#include <cctype>

bool measureResponseTime(const std::string& url,
                         double& milliseconds,
                         int& httpCode) {
    if (url.rfind("https://", 0) != 0 &&
        url.rfind("http://", 0) != 0) {
        return false;
    }

    // Accept only simple URLs in this first version.
    for (unsigned char ch : url) {
        if (!std::isalnum(ch) &&
            ch != ':' && ch != '/' &&
            ch != '.' && ch != '-' &&
            ch != '_') {
            return false;
        }
    }

    std::string command =
        "curl.exe -L -s -o NUL -w \"%{http_code}\" "
        "--max-time 10 \"" + url + "\" 2>NUL";

    auto start = std::chrono::steady_clock::now();

    FILE* pipe = _popen(command.c_str(), "r");
    if (pipe == nullptr) {
        return false;
    }

    char buffer[32];
    std::string output;

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        output += buffer;
    }

    int exitCode = _pclose(pipe);
    auto end = std::chrono::steady_clock::now();

    milliseconds =
        std::chrono::duration<double, std::milli>(
            end - start).count();

    try {
        httpCode = std::stoi(output);
    } catch (...) {
        return false;
    }

    return exitCode == 0 &&
           httpCode >= 100 && httpCode <= 599;
}