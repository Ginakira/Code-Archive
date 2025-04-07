// LeetCode 3396 使数组元素互不相同所需的最少操作次数

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
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num : nums) {
            ++cnt[num];
        }
        int ans = 0;
        int n = nums.size();
        int i = 0;
        do {
            if (n - i == cnt.size()) {
                return ans;
            }
            for (int j = i; j < i + 3 && j < n; ++j) {
                if (--cnt[nums[j]] == 0) {
                    cnt.erase(nums[j]);
                }
            }
            ++ans;
            i += 3;
        } while (i < n);
        return ans;
    }
};