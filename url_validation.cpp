
#include <iostream>
#include <string>
using namespace std;

// Function to validate website URL format
bool isValidURL(string url) {
    if (url.find("https://") == 0 ||
        url.find("http://") == 0) {
        return true;
    }

    return false;
}

// Function to display URL validation result
void validateWebsiteURL() {
    string url;

    cout << "Enter website URL: ";
    cin >> url;

    if (isValidURL(url)) {
        cout << "URL format is valid." << endl;
    } else {
        cout << "Invalid URL format!" << endl;
        cout << "URL must start with http:// or https://" << endl;
    }
}
