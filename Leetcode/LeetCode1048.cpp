// LeetCode 1048 最长字符串链

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
    int longestStrChain(vector<string> &words) {
        int ans = 0;
        unordered_map<string, int> word_to_max_len;
        sort(words.begin(), words.end(),
             [](auto &a, auto &b) { return a.size() < b.size(); });
        for (auto &word : words) {
            word_to_max_len[word] = 1;
            for (size_t i = 0; i < word.size(); ++i) {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (word_to_max_len.count(prev)) {
                    word_to_max_len[word] =
                        max(word_to_max_len[word], word_to_max_len[prev] + 1);
                }
            }
            ans = max(ans, word_to_max_len[word]);
        }
        return ans;
    }
};