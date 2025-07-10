// LeetCode 3169 无需开会的工作日

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
  int countDays(int days, vector<vector<int>>& meetings) {
    ranges::sort(meetings);
    int start = 1, end = 0;
    int meeting_days = 0;
    for (const auto& meeting : meetings) {
      int s = meeting[0], e = meeting[1];
      if (s > end) {
        meeting_days += end - start + 1;
        start = s;
      }
      end = max(end, e);
    }
    meeting_days += end - start + 1;
    return days - meeting_days;
  }
};
