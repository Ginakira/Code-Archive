// LeetCode 2799 统计完全子数组的数目

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
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int k = unordered_set<int>(nums.begin(), nums.end()).size();
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int l = 0, r = 0; l < n; ++l) {
            if (l > 0) {
                int to_remove = nums[l - 1];
                if (--cnt[to_remove] == 0) {
                    cnt.erase(to_remove);
                }
            }
            while (r < n && cnt.size() < k) {
                int to_add = nums[r];
                ++cnt[to_add];
                ++r;
            }
            if (cnt.size() == k) {
                ans += n - r + 1;
            }
        }
        return ans;
    }
};