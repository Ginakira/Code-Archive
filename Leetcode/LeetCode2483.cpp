// LeetCode 2483 商店的最少代价

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
  int bestClosingTime(string customers) {
    int n = customers.size();
    vector<int> y_sum(n + 1), n_sum(n + 1);
    for (int i = 0; i < n; ++i) {
      y_sum[i + 1] = y_sum[i];
      n_sum[i + 1] = n_sum[i];
      if (customers[i] == 'Y') {
        ++y_sum[i + 1];
      } else {
        ++n_sum[i + 1];
      }
    }
    int min_cost = numeric_limits<int>::max(), min_i = -1;
    for (int i = 0; i <= n; ++i) {
      int cost = n_sum[i] + y_sum[n] - y_sum[i];
      if (cost < min_cost) {
        min_cost = cost;
        min_i = i;
      }
    }
    return min_i;
  }
};