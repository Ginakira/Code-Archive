// LeetCode 215 数组中的第K个最大元素
#include <queue>
#include <vector>
using namespace std;

// STL 8ms
class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(),
                    greater<int>());
        return nums[k - 1];
    }
};

// 小顶堆 16ms
class Solution2 {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (const int& num : nums) {
            if (q.size() < k) {
                q.push(num);
                continue;
            }
            if (q.top() < num) {
                q.pop();
                q.push(num);
            }
        }
        return q.top();
    }
};