// LeetCode 2516 每种字符至少取 K 个

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
    bool is_valid(const std::array<int, 3> &cnt, int k) {
        return ranges::all_of(cnt, [k](auto &num) { return num >= k; });
    }

   public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int ans = n;
        array<int, 3> cnt{{0}};
        for (char c : s) {
            ++cnt[c - 'a'];
        }
        if (!is_valid(cnt, k)) {
            return -1;
        }
        for (int l = 0, r = 0; r < n; ++r) {
            --cnt[s[r] - 'a'];
            while (l < r && !is_valid(cnt, k)) {
                ++cnt[s[l] - 'a'];
                ++l;
            }
            int cost = n - (r - l + 1);
            if (is_valid(cnt, k)) {
                ans = min(ans, cost);
                continue;
            }
        }
        return ans;
    }
};