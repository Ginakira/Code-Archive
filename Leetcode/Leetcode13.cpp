// 罗马数字转整数
// 如果当前位后面的位权比前面高 则减去当前位 否则加上当前位
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char, int> romanToDec{{'I', 1},   {'V', 5},   {'X', 10},
                                    {'L', 50},  {'C', 100}, {'D', 500},
                                    {'M', 1000}};

class Solution {
   public:
    int romanToInt(string s) {
        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int value = romanToDec[s[i]];
            if (i < n - 1 && value < romanToDec[s[i + 1]]) {
                result -= value;
            } else {
                result += value;
            }
        }
        return result;
    }
};