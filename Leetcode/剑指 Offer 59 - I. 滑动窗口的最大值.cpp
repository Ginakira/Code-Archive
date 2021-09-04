// 剑指 Offer 59 - I. 滑动窗口的最大值

#include <algorithm>
#include <deque>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i < k - 1) continue;
            if (i - dq.front() >= k) dq.pop_front();
            result.push_back(nums[dq.front()]);
        }
        return result;
    }
};