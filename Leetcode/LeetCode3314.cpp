// LeetCode 3314 构造最小位运算数组 I

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
  vector<int> minBitwiseArray(vector<int>& nums) {
    for (int& x : nums) {
      int res = -1;
      int d = 1;
      while ((x & d) != 0) {
        res = x - d;
        d <<= 1;
      }
      x = res;
    }
    return nums;
  }
};