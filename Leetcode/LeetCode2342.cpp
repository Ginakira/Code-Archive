// LeetCode 2342 数位和相等数对的最大和

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
   private:
    constexpr int GetDigitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

   public:
    int maximumSum(vector<int>& nums) {
        std::unordered_map<int, int> mp;
        int ans = -1;
        for (int num : nums) {
            int ds = GetDigitSum(num);
            int cur_max = mp[ds];
            if (cur_max != 0) {
                ans = max(ans, num + cur_max);
            }
            if (num > cur_max) {
                mp[ds] = num;
            }
        }
        return ans;
    }
};