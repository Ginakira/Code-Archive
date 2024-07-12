// LeetCode 2974 最小数字游戏

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
#include <ranges>
using namespace std;

#include <ranges>
class Solution {
   public:
    vector<int> numberGame(vector<int>& nums) {
        ranges::sort(nums);
        for (auto subrange : nums | ranges::views::chunk(2)) {
            if (subrange.size() == 2) {
                swap(subrange[0], subrange[1]);
            }
        }
        return nums;
    }
};