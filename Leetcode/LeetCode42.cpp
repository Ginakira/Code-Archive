// 每日一题 接雨水
#include <stack>
#include <vector>
using namespace std;

// 维护一个单调递减单调栈
class Solution {
   public:
    int trap(vector<int>& height) {
        int ans = 0, len = height.size();
        stack<int> s;
        for (int i = 0; i < len; ++i) {
            while (!s.empty() && height[i] > height[s.top()]) {
                int cur = height[s.top()], left;
                s.pop();
                left = s.empty() ? -1 : s.top();
                ans += (left == -1 ? 0
                                   : (min(height[left], height[i]) - cur) *
                                         (i - left - 1));
            }
            s.push(i);
        }
        return ans;
    }
};