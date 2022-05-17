// LeetCode 953 验证外星语词典

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isAlienSorted(vector<string> &words, string order) {
        unordered_map<char, int> dict;
        for (size_t i = 0; i < order.size(); ++i) {
            dict[order[i]] = i;
        }

        bool sorted = is_sorted(
            words.begin(), words.end(),
            [&dict](const string &word_a, const string &word_b) {
                for (size_t i = 0, n = min(word_a.size(), word_b.size()); i < n;
                     ++i) {
                    int ind_a = dict[word_a[i]], ind_b = dict[word_b[i]];
                    if (ind_a == ind_b) continue;
                    return ind_a < ind_b;
                }
                return word_a.size() < word_b.size();
            });
        return sorted;
    }
};