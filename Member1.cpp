
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <chrono>

using namespace std;

// Encapsulation
class Website {
private:
    string url;
    string status;
    int httpCode;
    double responseTime;

public:
    Website(string u) {
        url = u;
        status = "NOT CHECKED";
        httpCode = 0;
        responseTime = 0;
    }

    string getURL() {
        return url;
    }

    string getStatus() {
        return status;
    }

    void setResult(string s, int code, double time) {
        status = s;
        httpCode = code;
        responseTime = time;
    }

    void display() {
        cout << "\nWebsite URL: " << url;
        cout << "\nStatus: " << status;
        cout << "\nHTTP Code: " << httpCode;
        cout << "\nResponse Time: " << responseTime << " ms\n";
    }
};

// Abstraction
class WebsiteMonitor {
public:
    virtual void checkWebsite(Website& website) = 0;

    virtual ~WebsiteMonitor() {}
};

// Inheritance and Polymorphism
class HTTPMonitor : public WebsiteMonitor {
public:
    void checkWebsite(Website& website) override {

        string url = website.getURL();

        if (url.find("http://") != 0 &&
            url.find("https://") != 0) {
            website.setResult("INVALID URL", 0, 0);
            return;
        }

        string command =
            "curl.exe -L -s -o NUL -w \"%{http_code}\" "
            "--max-time 10 \"" + url + "\"";

        auto start = chrono::steady_clock::now();

        FILE* pipe = _popen(command.c_str(), "r");

        if (pipe == NULL) {
            website.setResult("DOWN", 0, 0);
            return;
        }

        char buffer[20] = {0};
        string result;

        while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
            result += buffer;
        }

        int exitCode = _pclose(pipe);

        auto end = chrono::steady_clock::now();

        double time = chrono::duration<double, milli>(
            end - start).count();

        int code = 0;

        try {
            code = stoi(result);
        }
        catch (...) {
            code = 0;
        }

        string status;

        if (exitCode != 0 || code == 0) {
            status = "DOWN";
        }
        else if (code >= 200 && code < 400) {
            status = "UP";
        }
        else {
            status = "HTTP ERROR";
        }

        website.setResult(status, code, time);
    }
};

int main() {

    string url;

    cout << "===== WEBSITE UPTIME MONITOR =====\n";
    cout << "Enter website URL: ";
    cin >> url;

    Website website(url);

    HTTPMonitor http;

    // Runtime polymorphism
    WebsiteMonitor* monitor = &http;

    monitor->checkWebsite(website);

    website.display();

    return 0;
}
