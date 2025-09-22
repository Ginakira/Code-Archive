// LeetCode 3005 最大频率元素计数

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
  int maxFrequencyElements(vector<int>& nums) {
    std::array<int, 101> cnt{0};
    int max_cnt = 0, total_cnt = 0;
    for (int num : nums) {
      int c = ++cnt[num];
      if (c > max_cnt) {
        max_cnt = c;
        total_cnt = c;
      } else if (c == max_cnt) {
        total_cnt += c;
      }
    }
    return total_cnt;
  }
};