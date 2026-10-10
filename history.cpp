#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "history.h"

using namespace std;

// Save a website monitoring result to a file
void saveHistory(const string& website,
                 const string& status,
                 double responseTime) {

    ofstream file("monitoring_history.txt", ios::app);

    if (!file) {
        cout << "Error: Could not save monitoring history.\n";
        return;
    }

    time_t now = time(nullptr);
    string timestamp = ctime(&now);

    if (!timestamp.empty() && timestamp.back() == '\n') {
        timestamp.pop_back();
    }

    file << "Date and Time: " << timestamp << '\n';
    file << "Website: " << website << '\n';
    file << "Status: " << status << '\n';
    file << "Response Time: " << responseTime << " ms\n";
    file << "-----------------------------\n";

    file.close();

    cout << "Monitoring result saved successfully.\n";
}

// Display saved monitoring history
void viewHistory() {
    ifstream file("monitoring_history.txt");

    if (!file) {
        cout << "No monitoring history found yet.\n";
        return;
    }

    string line;

    cout << "\n===== MONITORING HISTORY =====\n";

    while (getline(file, line)) {
        cout << line << '\n';
    }

    file.close();
}