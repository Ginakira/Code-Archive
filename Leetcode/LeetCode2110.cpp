// LeetCode 2110 股票平滑下跌阶段的数目

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
  long long getDescentPeriods(vector<int>& prices) {
    int n = prices.size();
    long long ans = n;
    int len = 1;
    for (int i = 1; i < n; ++i) {
      if (prices[i - 1] - prices[i] != 1) {
        ans += 1LL * len * (len - 1) / 2;
        len = 1;
      } else {
        ++len;
      }
    }
    if (len > 1) {
      ans += 1LL * len * (len - 1) / 2;
    }
    return ans;
  }
};