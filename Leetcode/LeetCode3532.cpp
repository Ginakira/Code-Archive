// LeetCode 3532 针对图的路径存在性查询 I

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
  vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                    vector<vector<int>>& queries) {
    vector<int> id(n);
    for (int i = 1; i < n; ++i) {
      id[i] = id[i - 1] + (nums[i] - nums[i - 1] > maxDiff);
    }

    vector<bool> ans;
    ans.reserve(queries.size());
    for (const auto& q : queries) {
      ans.emplace_back(id[q[0]] == id[q[1]]);
    }
    return ans;
  }
};