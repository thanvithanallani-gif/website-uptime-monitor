
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cctype>

#include "response_time.h"
#include "uptime.h"

using namespace std;

// Function to remove unwanted spaces from URL
string trimURL(string url) {
    size_t first = url.find_first_not_of(" \t\n\r");

    if (first == string::npos)
        return "";

    size_t last = url.find_last_not_of(" \t\n\r");

    return url.substr(first, last - first + 1);
}

// ABSTRACT BASE CLASS
class WebsiteMonitor {

private:
    // ENCAPSULATION
    string websiteURL;
    int successfulChecks;
    int failedChecks;
    double averageResponseTime;
    double uptimePercentage;

protected:
    void updateResults(int success, int failed,
                       double average, double uptime) {

        successfulChecks = success;
        failedChecks = failed;
        averageResponseTime = average;
        uptimePercentage = uptime;
    }

public:

    // CONSTRUCTOR
    WebsiteMonitor(string url) {

        websiteURL = url;
        successfulChecks = 0;
        failedChecks = 0;
        averageResponseTime = 0;
        uptimePercentage = 0;
    }

    // GETTER FUNCTIONS
    string getURL() const {
        return websiteURL;
    }

    int getSuccessfulChecks() const {
        return successfulChecks;
    }

    int getFailedChecks() const {
        return failedChecks;
    }

    double getAverageResponseTime() const {
        return averageResponseTime;
    }

    double getUptime() const {
        return uptimePercentage;
    }

    // ABSTRACTION
    virtual void startMonitoring(int checks) = 0;

    virtual void displayReport() = 0;

    virtual ~WebsiteMonitor() {}
};


// INHERITANCE
class AdvancedWebsiteMonitor : public WebsiteMonitor {

public:

    // CHILD CLASS CONSTRUCTOR
    AdvancedWebsiteMonitor(string url)
        : WebsiteMonitor(url) {
    }

    // ACTUAL WEBSITE MONITORING
    void startMonitoring(int checks) override {

        int success = 0;
        int failed = 0;

        double totalResponseTime = 0;

        for (int i = 1; i <= checks; i++) {

            double milliseconds = 0;
            int httpCode = 0;

            cout << "\n===== CHECK "
                 << i << " =====\n";

            bool status = measureResponseTime(
                getURL(), milliseconds, httpCode
            );

            cout << fixed << setprecision(2);

            cout << "HTTP Code: "
                 << httpCode << endl;

            if (status) {

                success++;

                totalResponseTime += milliseconds;

                cout << "Website Status: UP\n";

                cout << "Response Time: "
                     << milliseconds << " ms\n";
            }
            else {

                failed++;

                cout << "Website Status: DOWN\n";

                cout << "Response Time: "
                     << milliseconds << " ms\n";
            }
        }

        double uptime = calculateUptimePercentage(
            success, checks
        );

        double average = 0;

        if (success > 0) {
            average = totalResponseTime / success;
        }

        updateResults(
            success,
            failed,
            average,
            uptime
        );
    }


    // POLYMORPHISM
    // Function overriding
    void displayReport() override {

        cout << "\n===== WEEK 4 OOP MONITOR REPORT =====\n";

        cout << "Website URL: "
             << getURL() << endl;

        cout << "Total Checks: "
             << getSuccessfulChecks() +
                getFailedChecks() << endl;

        cout << "Successful Checks: "
             << getSuccessfulChecks() << endl;

        cout << "Failed Checks: "
             << getFailedChecks() << endl;

        cout << fixed << setprecision(2);

        cout << "Uptime Percentage: "
             << getUptime() << "%\n";

        if (getSuccessfulChecks() > 0) {

            cout << "Average Response Time: "
                 << getAverageResponseTime()
                 << " ms\n";

            if (getAverageResponseTime() <= 300) {
                cout << "Performance: Fast\n";
            }
            else {
                cout << "Performance: Slow\n";
            }
        }
        else {
            cout << "Average Response Time: N/A\n";
        }

        cout << "Monitoring Completed!\n";
    }
};


// MAIN FUNCTION
int main() {

    string url;
    int checks;

    cout << "===== WEBSITE UPTIME MONITOR =====\n";

    cout << "Enter website URL: ";

    getline(cin, url);

    // Remove accidental leading/trailing spaces
    url = trimURL(url);

    if (url.empty()) {
        cout << "Website URL cannot be empty.\n";
        return 1;
    }

    cout << "How many times to check? ";

    if (!(cin >> checks) || checks <= 0) {
        cout << "Enter a valid positive number.\n";
        return 1;
    }

    // OBJECT CREATION
    AdvancedWebsiteMonitor website1(url);

    // RUNTIME POLYMORPHISM
    WebsiteMonitor* monitor = &website1;

    monitor->startMonitoring(checks);

    monitor->displayReport();

    return 0;
}
