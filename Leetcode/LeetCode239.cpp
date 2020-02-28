// 滑动窗口最大值
#include <vector>
using namespace std;

//单调队列问题 HZOJ#271
//维护区间最大值 单调递减序列，维护区间最小值，单调递增序列
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int q[n + 5], head = 0, tail = 0;
        for (int i = 0; i < n; ++i) {
            while (tail - head && nums[i] > nums[q[tail - 1]]) tail--;
            q[tail++] = i;
            if (i + 1 < k) continue;
            if (i - q[head] == k) head++;
            ans.push_back(nums[q[head]]);
        }
        return ans;
    }
};