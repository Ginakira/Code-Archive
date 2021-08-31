// 剑指 Offer 45. 把数组排成最小的数
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string minNumber(vector<int> &nums) {
        vector<string> strs;
        transform(nums.begin(), nums.end(), back_inserter(strs),
                  [](int a) { return to_string(a); });
        sort(strs.begin(), strs.end(),
             [](const string &a, const string &b) { return a + b < b + a; });
        return accumulate(strs.begin(), strs.end(), string());
    }
};