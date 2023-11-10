// LeetCode 2300 咒语和药水的成功对数

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
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        int n = spells.size(), m = potions.size();
        std::vector<int> ans;
        ans.reserve(n);
        std::sort(potions.begin(), potions.end());
        for (auto& spell : spells) {
            long long target = (success + spell - 1) / spell - 1;
            ans.emplace_back(
                m - (upper_bound(potions.begin(), potions.end(), target) -
                     potions.begin()));
        }
        return ans;
    }
};

class Solution2 {
   public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        int n = spells.size(), m = potions.size();
        std::vector<int> ans(n, 0);
        std::vector<int> idxs(n, 0);
        std::iota(idxs.begin(), idxs.end(), 0);
        std::sort(idxs.begin(), idxs.end(),
                  [&spells](int a, int b) { return spells[a] < spells[b]; });
        std::sort(potions.begin(), potions.end(), std::greater<int>());
        for (int i = 0, j = 0; i < n; ++i) {
            int idx = idxs[i];
            int spell = spells[idxs[i]];
            while (j < m && 1LL * potions[j] * spell >= success) {
                ++j;
            }
            ans[idx] = j;
        }
        return ans;
    }
};
