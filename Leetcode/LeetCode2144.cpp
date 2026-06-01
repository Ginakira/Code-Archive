// LeetCode 2144 打折购买糖果的最小开销

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
  int minimumCost(vector<int>& cost) {
    ranges::sort(cost, greater<int>{});
    auto chunk_sums =
        cost | views::chunk(3) | views::transform([](auto chunk) {
          return ranges::fold_left(chunk | views::take(2), 0, std::plus{});
        });
    return ranges::fold_left(chunk_sums, 0, std::plus{});
  }
};