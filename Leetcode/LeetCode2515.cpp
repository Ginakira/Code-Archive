// LeetCode 2515 到目标字符串的最短距离

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
  int closestTarget(vector<string>& words, string target, int startIndex) {
    int n = words.size();
    int ans = n;
    for (int i = 0; i < n; ++i) {
      if (words[i] == target) {
        int d = abs(i - startIndex);
        ans = min({ans, d, n - d});
      }
    }
    return ans == n ? -1 : ans;
  }
};