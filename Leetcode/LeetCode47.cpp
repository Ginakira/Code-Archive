// LeetCode 47 全排列II

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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        ranges::sort(nums);
        do {
            res.emplace_back(nums);
        } while (ranges::next_permutation(nums).found);
        return res;
    }
};