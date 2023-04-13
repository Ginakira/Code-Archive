// LeetCode 2404 出现最频繁的偶数元素

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = -1, ans_cnt = -1;
        for (int num : nums) {
            if (num & 1) {
                continue;
            }
            int cnt = ++mp[num];
            if (ans == 01 || cnt > ans_cnt || (cnt == ans_cnt && ans > num)) {
                ans = num;
                ans_cnt = cnt;
            }
        }
        return ans;
    }
};