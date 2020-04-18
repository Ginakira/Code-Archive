//每日一题 盛最多水的容器
#include <vector>
using namespace std;

// 双指针法 较短的一段向中间移动
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int ans = 0, n = height.size();
        int l = 0, r = n - 1;
        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};