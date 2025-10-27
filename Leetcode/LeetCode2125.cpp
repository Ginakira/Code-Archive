// LeetCode 2125 银行中的激光束数量

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
  int numberOfBeams(vector<string>& bank) {
    int pre_cnt = 0;
    int ans = 0;
    for (const auto& row : bank) {
      int cnt = ranges::count(row, '1');
      if (cnt > 0) {
        ans += cnt * pre_cnt;
        pre_cnt = cnt;
      }
    }
    return ans;
  }
};