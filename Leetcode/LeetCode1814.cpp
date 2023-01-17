// LeetCode 1814 统计一个数组中好对子的数目

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int rev(int num) {
        int ret = 0;
        while (num) {
            ret = ret * 10 + num % 10;
            num /= 10;
        }
        return ret;
    }

   public:
    int countNicePairs(vector<int>& nums) {
        constexpr int MOD = 1e9 + 7;
        int ans = 0;
        unordered_map<int, int> mp;
        for (int& num : nums) {
            int temp = num - rev(num);
            ans = (ans + mp[temp]) % MOD;
            ++mp[temp];
        }
        return ans;
    }
};