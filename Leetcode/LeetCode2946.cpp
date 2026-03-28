// LeetCode 2946 循环移位后的矩阵相似检查

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
  bool areSimilar(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size();
    k %= n;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] != mat[i][(j + k) % n]) {
          return false;
        }
      }
    }
    return true;
  }
};
