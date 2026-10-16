#include <iostream>
#include <string>

bool measureResponseTime(const std::string& url,
                         double& milliseconds,
                         int& httpCode);

int main() {
    std::string url;
    double milliseconds = 0;
    int httpCode = 0;

    std::cout << "Enter website URL: ";
    std::cin >> url;

    bool success = measureResponseTime(
        url, milliseconds, httpCode
    );

    if (success) {
        std::cout << "HTTP response code: "
                  << httpCode << '\n';

        std::cout << "Response time: "
                  << milliseconds << " ms\n";
    } else {
        std::cout << "Request failed or no valid "
                     "HTTP response was received.\n";
    }

    return 0;
}