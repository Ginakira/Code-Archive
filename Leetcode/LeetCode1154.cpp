// LeetCode 1154 一年中的第几天

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int dayOfYear(string date) {
        vector<int> days{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int year, month, day;
        year = stoi(date.substr(0, 4));
        month = stoi(date.substr(5, 2));
        day = stoi(date.substr(8, 2));

        if ((year % 4 == 0 && year % 100 != 0) ||
            (year % 400 == 0)) {  // leap year
            days[2] = 29;
        }

        int total_days =
            accumulate(days.begin(), days.begin() + month, 0) + day;
        return total_days;
    }
};