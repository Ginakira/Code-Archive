// LeetCode 3153 所有数对中数位差之和

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        while (nums[0] > 0) {
            array<int, 10> cnt{{0}};
            for (int i = 0; i < n; ++i) {
                ++cnt[nums[i] % 10];
                nums[i] /= 10;
            }
            for (int i = 0; i < 10; ++i) {
                ans += 1LL * cnt[i] * (n - cnt[i]);
            }
        }
        return ans / 2;
    }
};