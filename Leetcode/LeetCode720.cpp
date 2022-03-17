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
    string longestWord(vector<string> &words) {
        unordered_set<string> st(words.begin(), words.end());
        string ans;
        for (const string &word : words) {
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

class Solution2 {
   public:
    string longestWord(vector<string> &words) {
        sort(words.begin(), words.end(), [](auto &a, auto &b) {
            return (a.size() == b.size()) ? (a < b) : (a.size() > b.size());
        });

        unordered_set<string> st;
        for (auto &word : words) {
            st.insert(word);
        }

        string ans;
        for (auto &word : words) {
            bool valid = true;
            for (int i = 1; i < word.size(); ++i) {
                if (st.find(word.substr(0, i)) == st.end()) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans = word;
                break;
            }
        }
        return ans;
    }
};