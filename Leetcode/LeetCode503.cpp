// LeetCode 503 下一个更大元素 II
#include <stack>
#include <vector>
using namespace std;

// 548ms 暴力法
class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
                if (nums[j] > nums[i]) {
                    ans[i] = nums[j];
                    break;
                }
            }
        }
        return ans;
    }
};

// 48ms 单调栈 + 循环数组
// 将数组的前n - 1个元素拼接到原数组末尾（无需真实拼接，下标取模即可）
// 这样我们维护一个单调递减的单调栈
// 如果当前元素不符合单调性，那么我们就弹栈直到符合单调性
// 弹出的这些元素的答案就是当前的这位数字
class Solution2 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n * 2 - 1; ++i) {
            int idx = i % n;
            while (!stk.empty() && nums[stk.top()] < nums[idx])  {
                ans[stk.top()] = nums[idx];
                stk.pop();
            }
            stk.push(idx);
        }
        return ans;
    }
};