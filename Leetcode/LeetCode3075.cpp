// LeetCode 3075 幸福值最大化的选择方案

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
  long long maximumHappinessSum(vector<int>& happiness, int k) {
    long long ans = 0;
    ranges::sort(happiness, std::greater<int>());
    for (int i = 0; i < k && happiness[i] > i; ++i) {
      ans += happiness[i] - i;
    }
    return ans;
  }
};