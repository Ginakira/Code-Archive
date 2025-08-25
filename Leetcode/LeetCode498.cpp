// LeetCode 498 对角线遍历

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    size_t n = mat.size(), m = mat[0].size();
    vector<int> results;
    for (size_t i = 0; i < n + m - 1; ++i) {
      if (i & 1) {
        int x = i < m ? 0 : i - m + 1;
        int y = i < m ? i : m - 1;
        while (x < n && y >= 0) {
          results.emplace_back(mat[x][y]);
          ++x;
          --y;
        }
      } else {
        int x = i < n ? i : n - 1;
        int y = i < n ? 0 : i - n + 1;
        while (x >= 0 && y < m) {
          results.emplace_back(mat[x][y]);
          --x;
          ++y;
        }
      }
    }
    return results;
  }
};

class Solution2 {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    bool rev = false;
    vector<int> ans;
    ans.reserve(n * m);
    for (int i = 0, j = 0, cnt = 0; cnt < n * m; ++cnt) {
      ans.emplace_back(mat[i][j]);
      int d = rev ? -1 : 1;
      int ni = i - d, nj = j + d;
      if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
        if (ni < 0) {
          ni = 0;
        }
        if (nj < 0) {
          nj = 0;
        }
        if (ni >= n) {
          ni = n - 1;
          nj = j + 1;
        }
        if (nj >= m) {
          ni = i + 1;
          nj = m - 1;
        }
        rev = !rev;
      }
      i = ni, j = nj;
    }
    return ans;
  }
};