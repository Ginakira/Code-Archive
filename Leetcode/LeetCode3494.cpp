// LeetCode 3494 酿造药水需要的最少总时间

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
  long long minTime(vector<int>& skill, vector<int>& mana) {
    int n = skill.size(), m = mana.size();
    vector<long long> free_at(n, 0);
    for (int i = 0; i < m; ++i) {
      int cur_mana = mana[i];
      long long sum_t = 0;
      for (int j = 0; j < n; ++j) {
        sum_t = max(sum_t, free_at[j]) + skill[j] * cur_mana;
      }
      free_at.back() = sum_t;
      for (int j = n - 2; j >= 0; --j) {
        free_at[j] = free_at[j + 1] - skill[j + 1] * cur_mana;
      }
    }
    return free_at.back();
  }
};