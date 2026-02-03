// LeetCode 3637 分段式数组 I

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
  bool isTrionic(vector<int>& nums) {
    int n = nums.size();
    int p = 0;
    while (p < n - 1 && nums[p + 1] > nums[p]) {
      ++p;
    }
    if (p == 0) {
      return false;
    }
    int q = p;
    while (q < n - 1 && nums[q + 1] < nums[q]) {
      ++q;
    }
    if (p == q || q == n - 1) {
      return false;
    }
    for (int i = q; i < n - 1; ++i) {
      if (nums[i] >= nums[i + 1]) {
        return false;
      }
    }
    return true;
  }
};