// LeetCode 2410 运动员和训练师的最大匹配数

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
  int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    ranges::sort(players);
    ranges::sort(trainers);
    auto t_it = trainers.begin();
    int ans = 0;
    for (int player : players) {
      auto it = lower_bound(t_it, trainers.end(), player);
      if (it != trainers.end()) {
        t_it = ++it;
        ++ans;
      }
    }
    return ans;
  }
};