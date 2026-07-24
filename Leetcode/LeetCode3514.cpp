// LeetCode 3514 不同 XOR 三元组的数目 II

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
  int uniqueXorTriplets(vector<int>& nums) {
    int n = nums.size();
    int u = 1 << bit_width(1u * ranges::max(nums));

    vector<bool> has(u);
    for (int i = 0; i < n; ++i) {
      for (int j = i; j < n; ++j) {
        has[nums[i] ^ nums[j]] = true;
      }
    }

    vector<bool> has3(u);
    for (int xy = 0; xy < u; ++xy) {
      if (has[xy]) {
        for (int z : nums) {
          has3[xy ^ z] = true;
        }
      }
    }

    return reduce(has3.begin(), has3.end(), 0);
  }
};