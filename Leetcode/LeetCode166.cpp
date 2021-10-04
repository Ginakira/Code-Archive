// LeetCode 166 分数到小数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string fractionToDecimal(int numerator, int denominator) {
        if (int64_t(numerator) % denominator == 0) {
            return to_string(int64_t(numerator) / denominator);
        }
        int64_t up = abs(numerator), down = abs(denominator);
        string ans;
        if ((numerator < 0) ^ (denominator < 0)) {
            ans.push_back('-');
        }
        ans += to_string(up / down) + ".";
        unordered_map<int64_t, int> mp;
        up = up % down * 10;
        for (int i = ans.size(); up != 0; ++i) {
            if (mp.count(up)) {
                ans.insert(mp[up], "(");
                ans.push_back(')');
                break;
            }
            ans.push_back(up / down + '0');
            mp[up] = i;
            up = up % down * 10;
        }
        return ans;
    }
};