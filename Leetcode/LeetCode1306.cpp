// LeetCode 1306 跳跃游戏 III

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
  bool canReach(vector<int>& arr, int start) {
    int n = arr.size();
    vector<bool> vis(n);

    auto dfs = [&](this auto&& dfs, int i) -> bool {
      if (i < 0 || i >= n || vis[i]) {
        return false;
      }
      if (arr[i] == 0) {
        return true;
      }
      vis[i] = true;
      return dfs(i + arr[i]) || dfs(i - arr[i]);
    };

    return dfs(start);
  }
};