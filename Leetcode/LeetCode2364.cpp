// LeetCode 2364 统计坏数对的数目

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
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mark;
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ans += i - mark[nums[i] - i];
            ++mark[nums[i] - i];
        }
        return ans;
    }
};