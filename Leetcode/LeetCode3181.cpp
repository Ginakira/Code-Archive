// LeetCode 3181 执行操作可获得的最大总奖励II

#include <algorithm>
#include <array>
#include <bitset>
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
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        ranges::sort(rewardValues);
        if (n >= 2 && rewardValues[n - 2] == rewardValues[n - 1] - 1) {
            return 2 * rewardValues[n - 1] - 1;
        }
        constexpr int kMaxRewardValue = 2 * 50'000;
        bitset<kMaxRewardValue> dp0(0), dp1(0);
        dp0[0] = true;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < rewardValues[i]) {
                dp1[j] = dp0[j];
                ++j;
            }
            dp0 |= dp1 << rewardValues[i];  // same as j - x !!!!!!!
        }
        int ans = 0;
        for (int i = dp0.size() - 1; i >= 0; --i) {
            if (dp0[i]) {
                return i;
            }
        }
        return -1;
    }
};