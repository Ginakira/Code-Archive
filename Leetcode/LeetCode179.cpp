// LeetCode 179 最大数
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string largestNumber(vector<int> &nums) {
        // 全为0 返回0
        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
            return "0";
        }
        vector<string> strs(nums.size());
        transform(nums.begin(), nums.end(), strs.begin(),
                  [](const int &num) { return to_string(num); });
        sort(strs.begin(), strs.end(),
             [](const string &a, const string &b) { return a + b > b + a; });
        return accumulate(strs.begin(), strs.end(), string());
    }
};