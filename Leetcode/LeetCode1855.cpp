// LeetCode 1855 下标对中的最大距离

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
  int maxDistance(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    int ans = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
      while (j < m && nums1[i] <= nums2[j]) {
        ++j;
      }
      ans = max(ans, j - i - 1);
    }
    return ans;
  }
};