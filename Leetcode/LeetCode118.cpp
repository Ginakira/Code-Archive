// LeetCode 118 杨辉三角
#include <vector>
using namespace std;

// Solution1 0ms
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result(numRows, vector<int>{1});
    for (int row = 1; row < numRows; ++row) {
      for (int ind = 1; ind < row; ++ind) {
        result[row].push_back(result[row - 1][ind] + result[row - 1][ind - 1]);
      }
      result[row].push_back(1);
    }
    return result;
  }
};

class Solution2 {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    ans.reserve(numRows);
    for (int i = 0; i < numRows; ++i) {
      vector<int> row(i + 1, 1);
      for (int j = 1; j < i; ++j) {
        row[j] = ans.back()[j - 1] + ans.back()[j];
      }
      ans.emplace_back(std::move(row));
    }
    return ans;
  }
};