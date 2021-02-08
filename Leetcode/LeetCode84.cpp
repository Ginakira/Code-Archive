// 柱状图中最大的矩形
#include <stack>
#include <vector>
using namespace std;

//单调栈问题 HZOJ#264
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), top = -1;
        int h[n + 5], l[n + 5], r[n + 5], s[n + 5];
        //下标问题 将vector内元素转移到数组
        for (int i = 1; i <= n; ++i) {
            h[i] = heights[i - 1];
        }
        //两边高度为-1
        h[0] = h[n + 1] = -1;
        //扫描左边第一个小于当前高度的并存储
        s[++top] = 0;
        for (int i = 1; i <= n; ++i) {
            while (h[i] <= h[s[top]]) --top;
            l[i] = s[top];
            s[++top] = i;
        }
        //同上 栈清空 扫描右边
        top = -1;
        s[++top] = n + 1;
        for (int i = n; i > 0; --i) {
            while (h[i] <= h[s[top]]) --top;
            r[i] = s[top];
            s[++top] = i;
        }
        //计算最大面积
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, h[i] * (r[i] - l[i] - 1));
        }
        return ans;
    }
};

// C++容器
class Solution2 {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        heights.insert(heights.begin(), -1);
        heights.emplace_back(-1);
        vector<int> left(n + 2), right(n + 2);
        stack<int> normal_stk, reverse_stk;
        // Build decreasing stack, from left to right
        normal_stk.push(0);
        for (int i = 1; i <= n; ++i) {
            while (!normal_stk.empty() &&
                   heights[i] <= heights[normal_stk.top()]) {
                normal_stk.pop();
            }
            // The first lower height on its left
            left[i] = normal_stk.top();
            normal_stk.push(i);
        }
        // Build decreasing stack, from right to left
        reverse_stk.push(n + 1);
        for (int i = n; i > 0; --i) {
            while (!reverse_stk.empty() &&
                   heights[i] <= heights[reverse_stk.top()]) {
                reverse_stk.pop();
            }
            // The first lower height on its right
            right[i] = reverse_stk.top();
            reverse_stk.push(i);
        }
        // Calculate final answer
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
        }
        return ans;
    }
};