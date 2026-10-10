#ifndef HISTORY_H
#define HISTORY_H

#include <string>

void saveHistory(const std::string& website,
                 const std::string& status,
                 double responseTime);

void viewHistory();

#endif