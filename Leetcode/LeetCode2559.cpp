// LeetCode 2559 统计范围内的原因字符串数

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
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> valid_pre_sum(n + 1, 0);
        vector<int> ans;
        ans.reserve(queries.size());

        auto is_vowel = [](const string& word) -> bool {
            char ch_begin = word[0], ch_end = word.back();
            return (ch_begin == 'a' || ch_begin == 'e' || ch_begin == 'i' ||
                    ch_begin == 'o' || ch_begin == 'u') &&
                   (ch_end == 'a' || ch_end == 'e' || ch_end == 'i' ||
                    ch_end == 'o' || ch_end == 'u');
        };

        for (int i = 0; i < n; ++i) {
            valid_pre_sum[i + 1] = valid_pre_sum[i] + is_vowel(words[i]);
        }

        for (auto& query : queries) {
            int l = query[0], r = query[1];
            ans.emplace_back(valid_pre_sum[r + 1] - valid_pre_sum[l]);
        }
        return ans;
    }
};