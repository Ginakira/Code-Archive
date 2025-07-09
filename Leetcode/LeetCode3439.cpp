// LeetCode 3439 重新安排会议得到最多空余时间I

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
  int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                  vector<int>& endTime) {
    int n = startTime.size();
    vector<int> free(n + 1);
    free[0] = startTime[0];
    for (int i = 1; i < n; ++i) {
      free[i] = startTime[i] - endTime[i - 1];
    }
    free[n] = eventTime - endTime[n - 1];

    int ans = 0, cur = 0;
    for (int i = 0; i <= n; ++i) {
      cur += free[i];
      if (i < k) {
        continue;
      }
      ans = max(ans, cur);
      cur -= free[i - k];
    }
    return ans;
  }
};