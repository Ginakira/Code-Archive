// LeetCode 2654 使数组所有元素变成 1 的最少操作次数

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
  int minOperations(vector<int>& nums) {
    int n = nums.size(), gcd_all = 0, cnt1 = 0;
    for (int x : nums) {
      gcd_all = gcd(gcd_all, x);
      cnt1 += x == 1;
    }
    if (gcd_all > 1) {
      return -1;
    }
    if (cnt1 > 0) {
      return n - cnt1;
    }

    int min_size = n;
    for (int i = 0; i < n; ++i) {
      int g = 0;
      for (int j = i; j < n; ++j) {
        g = gcd(g, nums[j]);
        if (g == 1) {
          min_size = min(min_size, j - i + 1);
        }
      }
    }
    return min_size - 1 + n - 1;
  }
};