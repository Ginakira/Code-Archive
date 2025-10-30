// LeetCode 3289 数字小镇中的捣蛋鬼

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
  vector<int> getSneakyNumbers(vector<int>& nums) {
    unordered_set<int> mark;
    vector<int> ans;
    for (int num : nums) {
      if (mark.count(num)) {
        ans.emplace_back(num);
      }
      mark.emplace(num);
    }
    return ans;
  }
};

class Solution2 {
 public:
  vector<int> getSneakyNumbers(vector<int>& nums) {
    int n = nums.size() - 2;
    int y = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor());
    for (int i = 0; i < n; ++i) {
      y ^= i;
    }
    int low_bit = y & (-y);
    int x1 = 0, x2 = 0;
    for (int x : nums) {
      if (x & low_bit) {
        x1 ^= x;
      } else {
        x2 ^= x;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i & low_bit) {
        x1 ^= i;
      } else {
        x2 ^= i;
      }
    }
    return {x1, x2};
  }
};