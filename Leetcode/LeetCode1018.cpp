// LeetCode 1018 可被5整除的二进制前缀
#include <vector>
using namespace std;

class Solution {
 public:
  vector<bool> prefixesDivBy5(vector<int>& A) {
    vector<bool> ret;
    int sum = 0;
    for (const auto& bit : A) {
      sum <<= 1;
      sum |= bit;
      ret.emplace_back(sum % 5 == 0);
      sum %= 10;
    }
    return ret;
  }
};

class Solution2 {
 public:
  vector<bool> prefixesDivBy5(vector<int>& nums) {
    int n = nums.size();
    vector<bool> ans(n, false);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      cur = (cur << 1 | nums[i]) % 5;
      ans[i] = cur == 0;
    }
    return ans;
  }
};