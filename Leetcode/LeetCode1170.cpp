// LeetCode 1170 比较字符串最小字母出现频次

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
    int f(std::string &word) {
        sort(word.begin(), word.end());
        return upper_bound(word.begin(), word.end(), word[0]) - word.begin();
    }

   public:
    vector<int> numSmallerByFrequency(vector<string> &queries,
                                      vector<string> &words) {
        vector<int> words_cnt;
        vector<int> ans;
        words_cnt.reserve(words.size());
        ans.reserve(queries.size());

        for (auto &word : words) {
            words_cnt.emplace_back(f(word));
        }
        sort(words_cnt.begin(), words_cnt.end());

        for (auto &query : queries) {
            int val = f(query);
            ans.emplace_back(words_cnt.end() - upper_bound(words_cnt.begin(),
                                                           words_cnt.end(),
                                                           val));
        }
        return ans;
    }
};

class Solution2 {
   private:
    int f(const std::string &word) {
        int cnt = 0;
        char ch = 'z';
        for (char c : word) {
            if (c < ch) {
                cnt = 1;
                ch = c;
            } else if (c == ch) {
                ++cnt;
            }
        }
        return cnt;
    }

   public:
    vector<int> numSmallerByFrequency(vector<string> &queries,
                                      vector<string> &words) {
        vector<int> ans;
        array<int, 12> cnt{{0}};
        ans.reserve(queries.size());

        for (auto &word : words) {
            ++cnt[f(word)];
        }
        for (int i = 9; i >= 1; --i) {
            cnt[i] += cnt[i + 1];
        }

        for (auto &query : queries) {
            ans.emplace_back(cnt[f(query) + 1]);
        }
        return ans;
    }
};