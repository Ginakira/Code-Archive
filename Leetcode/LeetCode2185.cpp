// LeetCode 2185 统计包含给定前缀的字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int prefixCount(vector<string>& words, string pref) {
        string_view prefv{pref};
        int pref_n = prefv.size();
        return count_if(words.begin(), words.end(),
                        [prefv, pref_n](const string& word) {
                            string_view wordv{word};
                            return wordv.substr(0, pref_n) == prefv;
                        });
    }
};