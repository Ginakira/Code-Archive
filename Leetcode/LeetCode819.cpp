// LeetCode 819 最常见的单词

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> freq;
        unordered_set<string> banned_words(banned.begin(), banned.end());

        int max_cnt = 0;
        string max_cnt_word;

        size_t ind = 0, n = paragraph.size();
        auto is_delimiter = [](char ch) {
            return ch == ' ' || ch == '!' || ch == '?' || ch == '\'' ||
                   ch == ',' || ch == ';' || ch == '.';
        };
        while (ind < n) {
            string word;
            while (ind < n && !is_delimiter(paragraph[ind])) {
                word.push_back(tolower(paragraph[ind]));
                ++ind;
            }
            ++ind;
            if (word.empty() || banned_words.count(word)) {
                continue;
            }
            ++freq[word];
            if (freq[word] > max_cnt) {
                max_cnt = freq[word];
                max_cnt_word = word;
            }
        }

        return max_cnt_word;
    }
};