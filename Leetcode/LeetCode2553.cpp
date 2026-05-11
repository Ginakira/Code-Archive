// LeetCode 2553 分割数组中数字的数位

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
  vector<int> separateDigits(vector<int>& nums) {
    vector<int> ans;
    for (int num : nums) {
      string s = to_string(num);
      for (char ch : s) {
        ans.emplace_back(ch - '0');
      }
    }
    return ans;
  }
};