// LeetCode 1726 同积元组

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
    int tupleSameProduct(vector<int> &nums) {
        unordered_map<int, int> cnt;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ++cnt[nums[i] * nums[j]];
            }
        }
        for (auto &[k, v] : cnt) {
            ans += v * (v - 1) * 4;
        }
        return ans;
    }
};
