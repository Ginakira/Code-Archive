// LeetCode 2348 全 0 子数组的数目

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
  long long zeroFilledSubarray(vector<int>& nums) {
    int cur_cnt = 0;
    long long ans = 0;
    for (int num : nums) {
      if (num == 0) {
        ++cur_cnt;
        ans += cur_cnt;
      } else {
        cur_cnt = 0;
      }
    }
    return ans;
  }
};