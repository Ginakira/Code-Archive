// LeetCode 3432 统计元素和差值为偶数的分区方案

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
  int countPartitions(vector<int>& nums) {
    int sum = std::reduce(nums.begin(), nums.end());
    return (sum & 1) ? 0 : nums.size() - 1;
  }
};