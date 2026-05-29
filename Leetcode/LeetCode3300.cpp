// LeetCode 3300 替换为数位和以后的最小元素

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
  int minElement(vector<int>& nums) {
    int min_sum = numeric_limits<int>::max();
    for (int num : nums) {
      int sum = 0;
      while (num) {
        sum += num % 10;
        num /= 10;
      }
      min_sum = min(min_sum, sum);
    }
    return min_sum;
  }
};