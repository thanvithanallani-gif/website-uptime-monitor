#include <iostream>
#include "website_info.h"

using namespace std;

int main() {
    string url = "https://www.google.com/search";

    cout << "Website Name: "
         << getWebsiteName(url) << endl;

    return 0;
}