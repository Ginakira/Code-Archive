// LeetCode 1886 判断矩阵经轮转后是否一致

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
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    int n = mat.size();
    auto rotate = [&]() {
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          swap(mat[i][j], mat[j][i]);
        }
        ranges::reverse(mat[i]);
      }
    };

    for (int i = 0; i < 4; ++i) {
      if (mat == target) {
        return true;
      }
      rotate();
    }
    return false;
  }
};