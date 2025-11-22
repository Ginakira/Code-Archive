// LeetCode 3190 使所有元素都可以被 3 整除的最少操作次数

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
    int ans = 0;
    for (int num : nums) {
      ans += min(num % 3, 3 - num % 3);
    }
    return ans;
  }
};