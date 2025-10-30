// LeetCode 3289 数字小镇中的捣蛋鬼

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
  vector<int> getSneakyNumbers(vector<int>& nums) {
    unordered_set<int> mark;
    vector<int> ans;
    for (int num : nums) {
      if (mark.count(num)) {
        ans.emplace_back(num);
      }
      mark.emplace(num);
    }
    return ans;
  }
};