// LeetCode 1437 是否所有 1 都至少相隔 k 个元素

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
  bool kLengthApart(vector<int>& nums, int k) {
    int pre = -k - 1;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 1) {
        if (i - pre - 1 < k) {
          return false;
        }
        pre = i;
      }
    }
    return true;
  }
};