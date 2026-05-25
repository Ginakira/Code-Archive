// LeetCode 1871 跳跃游戏 VII

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
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.size();
    vector<bool> can_reaches(n);
    can_reaches[0] = true;

    int j = 1;
    for (int i = 0; i < n && j < n; ++i) {
      if (s[i] == '0' && can_reaches[i]) {
        for (j = max(j, i + minJump); j <= min(i + maxJump, n - 1); ++j) {
          can_reaches[j] = true;
        }
      }
    }

    return s[n - 1] == '0' && can_reaches[n - 1];
  }
};