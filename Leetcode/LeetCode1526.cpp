// LeetCode 1526 形成目标数组的子数组最少操作次数

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
  int minNumberOperations(vector<int>& target) {
    int n = target.size();
    int ans = target[0];
    for (int i = 1; i < n; ++i) {
      ans += max(target[i] - target[i - 1], 0);
    }
    return ans;
  }
};