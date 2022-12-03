// LeetCode 1796 字符串中第二大的数字

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int secondHighest(string s) {
        int max1 = -1, max2 = -1;
        for (char c : s) {
            if (!isdigit(c)) {
                continue;
            }
            int num = c - '0';
            if (num > max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2 && num < max1) {
                max2 = num;
            }
        }
        return max2;
    }
};