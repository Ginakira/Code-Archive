// LeetCode 1177 构建回文串检测

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
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> presum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int bit = 1 << (s[i] - 'a');
            presum[i + 1] =
                presum[i] ^
                bit;  // 该比特对应字母的奇偶性：奇数变偶数，偶数变奇数
        }

        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto& query : queries) {
            int left = query[0], right = query[1], k = query[2];
            int cnt = __builtin_popcount(presum[right + 1] ^ presum[left]);
            ans.emplace_back(cnt / 2 <= k);
        }
        return ans;
    }
};