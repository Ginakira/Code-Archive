// LeetCode 1078 Bigram 分词

#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        vector<string> words;
        stringstream ss(text);
        string str;
        while (ss >> str) {
            words.push_back(str);
        }
        size_t n = words.size();
        for (size_t i = 0; i < n - 2; ++i) {
            if (words[i] != first || words[i + 1] != second) continue;
            ans.push_back(words[i + 2]);
        }
        return ans;
    }
};