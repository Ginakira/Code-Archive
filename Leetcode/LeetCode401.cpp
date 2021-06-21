// LeetCode 401 二进制手表
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 枚举合法时间
class Solution {
   public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for (int h = 0; h <= 11; ++h) {
            for (int m = 0; m <= 59; ++m) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    result.push_back(to_string(h) + (m < 10 ? ":0" : ":") +
                                     to_string(m));
                }
            }
        }
        return result;
    }
};

// 二进制枚举 高4位为小时 低四位为分钟
class Solution2 {
   public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for (int i = 0; i < 1024; ++i) {
            int h = i >> 6, m = i & 63;
            if (h < 12 && m < 60 && __builtin_popcount(i) == turnedOn) {
                result.push_back(to_string(h) + (m < 10 ? ":0" : ":") +
                                 to_string(m));
            }
        }
        return result;
    }
};