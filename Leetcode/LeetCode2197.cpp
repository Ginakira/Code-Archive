// LeetCode 2197 替换数组中的非互质数

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
  vector<int> replaceNonCoprimes(vector<int>& nums) {
    vector<int> ans;
    ans.reserve(nums.size());
    for (int num : nums) {
      while (!ans.empty()) {
        if (gcd(num, ans.back()) > 1) {
          num = lcm(ans.back(), num);
          ans.pop_back();
        } else {
          break;
        }
      }
      ans.emplace_back(num);
    }
    return ans;
  }
};