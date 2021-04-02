// 面试题 17.21. 直方图的水量
#include <stack>
#include <vector>
using namespace std;

// 单调栈
class Solution {
   public:
    int trap(vector<int>& height) {
        int ans = 0, n = height.size();
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[stk.top()] < height[i]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int left = stk.top();
                ans += (min(height[left], height[i]) - height[top]) *
                       (i - left - 1);
            }
            stk.push(i);
        }
        return ans;
    }
};

// 数组预处理
class Solution2 {
   public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int ans = 0, n = height.size();
        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0], right_max[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i) {
            left_max[i] = max(left_max[i - 1], height[i]);
            right_max[n - i - 1] = max(right_max[n - i], height[n - i - 1]);
        }
        for (int i = 0; i < n; ++i) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};