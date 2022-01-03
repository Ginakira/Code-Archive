// LeetCode 1185 一周中的第几天

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string dayOfTheWeek(int day, int month, int year) {
        const string week_day_text[] = {"Monday",   "Tuesday", "Wednesday",
                                        "Thursday", "Friday",  "Saturday",
                                        "Sunday"};
        int month_to_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int days = 365 * (year - 1971) + (year - 1969) / 4;
        for (int i = 0; i < month - 1; ++i) {
            days += month_to_days[i];
        }
        if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) &&
            month >= 3) {
            days += 1;
        }
        days += day;
        return week_day_text[(days + 3) % 7];
    }
};