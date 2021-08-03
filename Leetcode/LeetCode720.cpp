// LeetCode 720 词典中最长的单词

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    string longestWord(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        string ans;
        for (const string& word : words) {
            if (word.size() < ans.size()) continue;
            bool valid = true;
            for (int i = 1; i < word.size(); ++i) {
                if (!st.count(word.substr(0, i))) {
                    valid = false;
                    break;
                }
            }
            if (valid && (word.size() > ans.size() || word < ans)) {
                ans = word;
            }
        }
        return ans;
    }
};