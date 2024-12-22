// LeetCode 1387 将整数按权重排序

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <ranges>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int getKth(int lo, int hi, int k) {
        auto get_w = [](int x) {
            int cnt = 0;
            while (x != 1) {
                if (x & 1) {
                    x = 3 * x + 1;
                } else {
                    x /= 2;
                }
                ++cnt;
            }
            return cnt;
        };
        vector<int> nums(hi - lo + 1);
        ranges::iota(nums, lo);
        ranges::sort(nums, [&](int a, int b) {
            int wa = get_w(a);
            int wb = get_w(b);
            if (wa == wb) {
                return a < b;
            }
            return wa < wb;
        });
        return nums[k - 1];
    }
};

class Solution2 {
   public:
    int getKth(int lo, int hi, int k) {
        unordered_map<int, int> mem;
        std::function<int(int)> get_w = [&](int x) {
            if (mem.count(x)) {
                return mem[x];
            }
            if (x == 1) {
                return 0;
            }
            if (x & 1) {
                mem[x] = get_w(3 * x + 1) + 1;
            } else {
                mem[x] = get_w(x / 2) + 1;
            }
            return mem[x];
        };
        vector<int> nums(hi - lo + 1);
        ranges::iota(nums, lo);
        ranges::sort(nums, [&](int a, int b) {
            int wa = get_w(a);
            int wb = get_w(b);
            if (wa == wb) {
                return a < b;
            }
            return wa < wb;
        });
        return nums[k - 1];
    }
};