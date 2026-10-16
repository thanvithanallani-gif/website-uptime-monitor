#ifndef URL_VALIDATOR_H
#define URL_VALIDATOR_H

#include <string>
#include <cctype>

inline bool isValidURL(const std::string& url) {
    std::string prefix;

    if (url.rfind("https://", 0) == 0) {
        prefix = "https://";
    }
    else if (url.rfind("http://", 0) == 0) {
        prefix = "http://";
    }
    else {
        return false;
    }

    std::string hostname = url.substr(prefix.length());

    if (hostname.empty()) {
        return false;
    }

    if (hostname.find('.') == std::string::npos) {
        return false;
    }

    if (hostname.front() == '.' ||
        hostname.back() == '.') {
        return false;
    }

    return true;
}

#endif