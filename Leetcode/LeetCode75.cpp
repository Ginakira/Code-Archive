// LeetCode 75 颜色分类

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
    void sortColors(vector<int>& nums) {
        int red_cnt = 0, white_cnt = 0, blue_cnt = 0;
        for (int num : nums) {
            if (num == 0) {
                ++red_cnt;
            } else if (num == 1) {
                ++white_cnt;
            } else {
                ++blue_cnt;
            }
        }
        for (int& num : nums) {
            if (red_cnt-- > 0) {
                num = 0;
            } else if (white_cnt-- > 0) {
                num = 1;
            } else if (blue_cnt-- > 0) {
                num = 2;
            }
        }
    }
};

class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            } else if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                ++p1;
            }
        }
    }
};