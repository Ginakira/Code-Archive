// LeetCode 1861 旋转盒子

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
  vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
    int m = boxGrid.size(), n = boxGrid[0].size();
    vector<vector<char>> result(n, vector<char>(m, '.'));
    for (int i = 0; i < m; ++i) {
      auto& row = boxGrid[i];
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        char ch = row[j];
        if (ch == '#') {  // Stone
          ++cnt;
          ch = '.';
        }
        result[j][m - i - 1] = ch;
        if (j == n - 1 || row[j + 1] == '*') {
          for (int k = j; k > j - cnt; --k) {
            result[k][m - i - 1] = '#';
          }
          cnt = 0;
        }
      }
    }
    return result;
  }
};