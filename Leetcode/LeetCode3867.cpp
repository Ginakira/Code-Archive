// LeetCode 3867 数对的最大公约数之和

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
  long long gcdSum(vector<int>& nums) {
    int cur_max = 0;
    int n = nums.size();
    vector<int> prefix_gd(n);
    for (int i = 0; i < n; ++i) {
      cur_max = max(cur_max, nums[i]);
      prefix_gd[i] = gcd(nums[i], cur_max);
    }
    ranges::sort(prefix_gd);
    long long ans = 0;
    for (int i = 0; i < n / 2; ++i) {
      ans += gcd(prefix_gd[i], prefix_gd[n - i - 1]);
    }
    return ans;
  }
};