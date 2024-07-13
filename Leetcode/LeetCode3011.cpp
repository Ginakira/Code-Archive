// LeetCode 3011 判断一个数组是否可以变为有序

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
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        int last_cnt = 0;
        int last_max = 0;
        int cur_max = 0;

        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            int cnt = __builtin_popcount(num);
            if (cnt == last_cnt) {
                cur_max = max(cur_max, num);
            } else {
                last_cnt = cnt;
                last_max = cur_max;
                cur_max = num;
            }
            if (num < last_max) {
                return false;
            }
        }
        return true;
    }
};
