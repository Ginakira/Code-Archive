// LeetCode 1010 总持续时间可被60整除的歌曲

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
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int ans = 0;
        array<int, 60> mods{{0}};
        for (int t : time) {
            ++mods[t % 60];
        }
        for (int i = 1; i < 30; ++i) {
            ans += mods[i] * mods[60 - i];
        }
        ans += (long long)mods[0] * (mods[0] - 1) / 2 +
               (long long)mods[30] * (mods[30] - 1) / 2;
        return ans;
    }
};