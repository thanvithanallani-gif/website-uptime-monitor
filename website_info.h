#ifndef WEBSITE_INFO_H
#define WEBSITE_INFO_H

#include <string>

inline std::string getWebsiteName(const std::string& url) {
    std::string::size_type start;

    if (url.find("https://") == 0) {
        start = 8;
    }
    else if (url.find("http://") == 0) {
        start = 7;
    }
    else {
        return "Invalid URL";
    }

    std::string hostname = url.substr(start);

    std::string::size_type end = hostname.find_first_of("/:?#");

    if (end != std::string::npos) {
        hostname = hostname.substr(0, end);
    }

    if (hostname.empty()) {
        return "Invalid URL";
    }

    return hostname;
}

#endif