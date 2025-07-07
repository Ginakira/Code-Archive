// LeetCode 1353 最多可以参加的会议数目

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
  int maxEvents(vector<vector<int>>& events) {
    int n = events.size();
    int ans = 0;
    int max_d = 0;
    for (const auto& e : events) {
      max_d = max(max_d, e[1]);
    }
    ranges::sort(events);
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0, j = 0; i <= max_d; ++i) {
      while (j < n && events[j][0] <= i) {
        pq.emplace(events[j][1]);
        ++j;
      }
      while (!pq.empty() && pq.top() < i) {
        pq.pop();
      }
      if (!pq.empty()) {
        pq.pop();
        ++ans;
      }
    }
    return ans;
  }
};