#include <algorithm>
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