#include <iostream>
#include "response_time_utils.h"
using namespace std;

int main() {
    cout << formatResponseTime(250) << endl;
    cout << formatResponseTime(1500) << endl;
    cout << formatResponseTime(5000) << endl;

    return 0;
}