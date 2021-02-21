// LeetCode 1438 绝对差不超过限制的最长连续子数组
#include <deque>
#include <set>
#include <vector>
using namespace std;

// S1: multiset 240ms 76.8MB
class Solution {
   public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> ms;
        int left = 0, right = 0, max_len = 0;
        while (right < n) {
            ms.insert(nums[right]);
            while (abs(*ms.begin() - *ms.rbegin()) > limit) {
                auto pos = ms.find(nums[left]);
                if (pos != ms.end()) {
                    ms.erase(pos);
                }
                ++left;
            }
            max_len = max(max_len, right - left + 1);
            ++right;
        }
        return max_len;
    }
};

// S2: deque 112ms 50.7MB
class Solution2 {
   public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> min_q, max_q;
        int left = 0, right = 0, max_len = 0;
        while (right < n) {
            while (!min_q.empty() && nums[right] < min_q.back()) {
                min_q.pop_back();
            }
            while (!max_q.empty() && nums[right] > max_q.back()) {
                max_q.pop_back();
            }
            min_q.push_back(nums[right]);
            max_q.push_back(nums[right]);
            while (!min_q.empty() && !max_q.empty() &&
                   max_q.front() - min_q.front() > limit) {
                if (min_q.front() == nums[left]) {
                    min_q.pop_front();
                }
                if (max_q.front() == nums[left]) {
                    max_q.pop_front();
                }
                ++left;
            }
            max_len = max(max_len, right - left + 1);
            ++right;
        }
        return max_len;
    }
};