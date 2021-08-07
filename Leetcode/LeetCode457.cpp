// LeetCode 457 环形数组是否存在循环

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 模拟
class Solution {
   public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        auto check = [&](int start) {
            int cur = start;
            int steps = 1;
            bool flag = nums[start] > 0;
            while (true) {
                if (steps > n) return false;
                int next = ((cur + nums[cur]) % n + n) % n;
                if (flag && nums[next] < 0) return false;
                if (!flag && nums[next] > 0) return false;
                if (next == start) return steps > 1;
                cur = next;
                ++steps;
            }
        };

        for (int i = 0; i < n; ++i) {
            if (check(i)) return true;
        }
        return false;
    }
};

// 使用原数组标记
class Solution2 {
   public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        auto next = [&](int cur) { return ((cur + nums[cur]) % n + n) % n; };

        for (int i = 0; i < n; ++i) {
            if (!nums[i]) continue;
            int slow = i, fast = next(i);
            while (nums[slow] * nums[fast] > 0 &&
                   nums[slow] * nums[next(fast)] > 0) {
                if (slow == fast) {
                    if (slow != next(slow)) {
                        return true;
                    } else {
                        break;
                    }
                }
                slow = next(slow);
                fast = next(next(fast));
            }

            int cur = i;
            while (nums[cur] * nums[next(cur)] > 0) {
                nums[cur] = 0;
                cur = next(cur);
            }
        }
        return false;
    }
};