// LeetCode 1578 使绳子变成彩色的最短时间

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
  int minCost(string colors, vector<int>& neededTime) {
    int ans = 0;
    int cur_max = 0, cur_sum = 0;
    char pre_color = colors[0];
    int n = colors.size();
    for (int i = 0; i < n; ++i) {
      char color = colors[i];
      int time = neededTime[i];
      if (color == pre_color) {
        cur_sum += time;
        cur_max = max(cur_max, time);
      } else {
        pre_color = color;
        ans += cur_sum - cur_max;
        cur_sum = cur_max = time;
      }
    }
    ans += cur_sum - cur_max;
    return ans;
  }
};