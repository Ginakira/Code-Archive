// LeetCode 3379 转换数组

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
  vector<int> constructTransformedArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 0);
    for (int i = 0; i < n; ++i) {
      int num = nums[i];
      if (num == 0) {
        result[i] = num;
      } else if (num < 0) {
        result[i] = nums[(i + n - abs(num) % n) % n];
      } else {
        result[i] = nums[(i + num) % n];
      }
    }
    return result;
  }
};