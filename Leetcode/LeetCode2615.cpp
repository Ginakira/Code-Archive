// LeetCode 2615 等值距离和

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
  vector<long long> distance(vector<int>& nums) {
    int n = nums.size();
    vector<long long> ans(n);
    unordered_map<int, vector<int>> idxs;
    for (int i = 0; i < n; ++i) {
      idxs[nums[i]].emplace_back(i);
    }
    vector<long long> s(n + 1);
    for (const auto& [_, idx] : idxs) {
      int m = idx.size();
      for (int i = 0; i < m; ++i) {
        s[i + 1] = s[i] + idx[i];
      }
      for (int i = 0; i < m; ++i) {
        long long target = idx[i];
        long long left = target * i - s[i];
        long long right = s[m] - s[i] - target * (m - i);
        ans[target] = left + right;
      }
    }
    return ans;
  }
};