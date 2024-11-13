// LeetCode 3261 统计满足K约束的子字符串数量II

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
    vector<long long> countKConstraintSubstrings(string s, int k,
                                                 vector<vector<int>>& queries) {
        int n = s.size();
        array<int, 2> cnt{0, 0};
        vector<int> left(n);
        vector<long long> pre_sum(n + 1, 0);
        for (int i = 0, l = 0; i < n; ++i) {
            ++cnt[s[i] - '0'];
            while (cnt[0] > k && cnt[1] > k) {
                --cnt[s[l++] - '0'];
            }
            left[i] = l;
            pre_sum[i + 1] = pre_sum[i] + i - l + 1;
        }

        vector<long long> ans;
        ans.reserve(queries.size());
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            int j = lower_bound(left.begin() + l, left.begin() + r + 1, l) -
                    left.begin();
            ans.emplace_back(pre_sum[r + 1] - pre_sum[j] +
                             1LL * (j - l + 1) * (j - l) / 2);
        }
        return ans;
    }
};