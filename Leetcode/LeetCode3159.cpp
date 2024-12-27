// LeetCode 3159 查询数组中元素的出现位置

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
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries,
                                     int x) {
        vector<int> idx;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == x) {
                idx.emplace_back(i);
            }
        }
        vector<int> ans;
        for (const auto& query : queries) {
            if (query > idx.size()) {
                ans.emplace_back(-1);
            } else {
                ans.emplace_back(idx[query - 1]);
            }
        }
        return ans;
    }
};