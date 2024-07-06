// LeetCode 3101 交替子数组计数

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
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        long long cur_cnt = 0;
        int pre = -1;
        for (int num : nums) {
            cur_cnt = num != pre ? cur_cnt + 1 : 1;
            pre = num;
            ans += cur_cnt;
        }
        return ans;
    }
};