// LeetCode 3296 移山所需的最小秒数

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
  long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    using TLLI = tuple<long long, long long, int>;
    priority_queue<TLLI, vector<TLLI>, greater<>> pq;
    for (int t : workerTimes) {
      pq.emplace(t, t, t);
    }
    long long ans = 0;
    while (mountainHeight--) {
      auto [total, cur, worker_time] = pq.top();
      pq.pop();
      ans = total;
      pq.emplace(total + cur + worker_time, cur + worker_time, worker_time);
    }
    return ans;
  }
};