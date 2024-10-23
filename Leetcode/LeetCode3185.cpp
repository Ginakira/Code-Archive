// LeetCode 3185 构成整天的下标对数目 II

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
    long long countCompleteDayPairs(vector<int>& hours) {
        std::array<int, 24> cnt = {0};
        long long ans = 0;
        for (int hour : hours) {
            hour %= 24;
            ans += cnt[hour ? 24 - hour : 0];
            ++cnt[hour];
        }
        return ans;
    }
};