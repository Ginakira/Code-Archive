// LeetCode 3440 重新安排会议得到最多空余时间 II

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
  int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();

    auto get_section_len = [&](int i) {
      if (i == 0) {
        return startTime[0];
      }
      if (i == n) {
        return eventTime - endTime[i - 1];
      }
      return startTime[i] - endTime[i - 1];
    };

    int a = 0, b = -1, c = -1;
    for (int i = 1; i <= n; ++i) {
      int sz = get_section_len(i);
      if (sz > get_section_len(a)) {
        c = b;
        b = a;
        a = i;
      } else if (b < 0 || sz > get_section_len(b)) {
        c = b;
        b = i;
      } else if (c < 0 || sz > get_section_len(c)) {
        c = i;
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int sz = endTime[i] - startTime[i];
      if (i != a && i + 1 != a && sz <= get_section_len(a) ||
          i != b && i + 1 != b && sz <= get_section_len(b) ||
          sz <= get_section_len(c)) {
        ans = max(ans, get_section_len(i) + sz + get_section_len(i + 1));
      } else {
        ans = max(ans, get_section_len(i) + get_section_len(i + 1));
      }
    }
    return ans;
  }
};