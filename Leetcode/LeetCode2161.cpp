// LeetCode 2161 根据给定数字划分数组

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
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size();
    vector<int> ans(n, pivot);
    int left = 0, right = n - 1;
    for (int i = 0; i < n; ++i) {
      if (nums[i] < pivot) {
        ans[left++] = nums[i];
      } else if (nums[i] > pivot) {
        ans[right--] = nums[i];
      }
    }
    reverse(ans.begin() + right + 1, ans.end());
    return ans;
  }
};