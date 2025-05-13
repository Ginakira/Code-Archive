// LeetCode 3335 字符串转换后的长度 I

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
    int lengthAfterTransformations(string s, int t) {
        constexpr static int MOD = 1e9 + 7;
        array<int, 26> cnt{{0}};
        for (char ch : s) {
            ++cnt[ch - 'a'];
        }
        for (int round = 0; round < t; ++round) {
            array<int, 26> next{{0}};
            next[0] = cnt[25];
            next[1] = (cnt[25] + cnt[0]) % MOD;
            for (int i = 2; i < 26; ++i) {
                next[i] = cnt[i - 1];
            }
            cnt = move(next);
        }
        int ans = 0;
        for (int num : cnt) {
            ans = (ans + num) % MOD;
        }
        return ans;
    }
};