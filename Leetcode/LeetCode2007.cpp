// LeetCode 2007 从双倍数组中还原原数组

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n & 1) {
            return {};
        }
        multiset<int> ms(changed.begin(), changed.end());
        vector<int> ans;
        ans.reserve(n / 2);
        while (ms.size() >= 2) {
            auto num = *ms.begin();
            ms.erase(ms.begin());
            auto it = ms.find(num * 2);
            if (it == ms.end()) {
                return {};
            }
            ms.erase(it);
            ans.emplace_back(num);
        }
        if (!ms.empty()) {
            return {};
        }
        return ans;
    }
};

class Solution2 {
   public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n & 1) {
            return {};
        }
        unordered_map<int, int> cnt;
        for (auto num : changed) {
            ++cnt[num];
        }
        vector<int> ans;
        ans.reserve(n / 2);
        ranges::sort(changed);
        for (auto& num : changed) {
            if (cnt[num] == 0) {
                continue;
            }
            --cnt[num];
            if (cnt[num * 2] == 0) {
                return {};
            }
            --cnt[num * 2];
            ans.emplace_back(num);
        }
        return ans;
    }
};
