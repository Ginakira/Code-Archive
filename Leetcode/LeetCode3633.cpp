// LeetCode 3633 最早完成陆地和水上游乐设施的时间 I

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
  int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                         vector<int>& waterStartTime,
                         vector<int>& waterDuration) {
    auto solve = [](const auto& land_start, const auto& land_dur,
                    const auto& water_start, const auto& water_dur) -> int {
      int min_land_end = numeric_limits<int>::max();
      for (int i = 0; i < land_start.size(); ++i) {
        min_land_end = min(min_land_end, land_start[i] + land_dur[i]);
      }
      int ans = numeric_limits<int>::max();
      for (int i = 0; i < water_start.size(); ++i) {
        ans = min(ans, max(water_start[i], min_land_end) + water_dur[i]);
      }
      return ans;
    };

    return min(
        solve(landStartTime, landDuration, waterStartTime, waterDuration),
        solve(waterStartTime, waterDuration, landStartTime, landDuration));
  }
};