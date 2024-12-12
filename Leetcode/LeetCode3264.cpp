// LeetCode 3264 K次乘运算后的最终数组I

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
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; ++i) {
            auto& elem = *ranges::min_element(nums);
            elem *= multiplier;
        }
        return nums;
    }
};

class Solution {
   public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        using TII = tuple<int, int>;
        priority_queue<TII, vector<TII>, greater<TII>> pq;
        for (int i = 0; i < nums.size(); ++i) {
            pq.emplace(nums[i], i);
        }
        for (int i = 0; i < k; ++i) {
            auto [val, idx] = pq.top();
            pq.pop();
            val *= multiplier;
            pq.emplace(val, idx);
        }
        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            nums[idx] = val;
            pq.pop();
        }
        return nums;
    }
};