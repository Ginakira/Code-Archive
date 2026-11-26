// LeetCode 3360 移除石头游戏

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
  bool canAliceWin(int n) {
    bool ans = false;
    int cur = 10;
    while (n >= cur) {
      n -= cur;
      --cur;
      ans = !ans;
    }
    return ans;
  }
};