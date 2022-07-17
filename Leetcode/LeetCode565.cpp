// LeetCode 565 数组嵌套

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int arrayNesting(vector<int>& nums) {
        int max_ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int cur = i, cnt = 0;
            while (nums[cur] != -1) {
                ++cnt;
                int origin = cur;
                cur = nums[cur];
                nums[origin] = -1;
            }
            max_ans = max(max_ans, cnt);
        }
        return max_ans;
    }
};