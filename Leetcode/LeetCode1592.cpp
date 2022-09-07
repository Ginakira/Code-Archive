// LeetCode 1592 重新排列单词间的空格

#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string reorderSpaces(string text) {
        int blank_cnt = count(text.begin(), text.end(), ' ');
        stringstream ss(text);
        vector<string> words;
        string s;
        while (ss >> s) {
            words.emplace_back(move(s));
        }

        int n = words.size();
        int blank_insert = blank_cnt / max(n - 1, 1),
            blank_remain = blank_cnt - blank_insert * n;
        string result;
        for (auto &&word : words) {
            result.append(move(word));
            result.append(string(blank_insert, ' '));
        }
        if (blank_remain > 0) {
            result.append(string(blank_remain, ' '));
        } else {
            result = move(result.substr(0, result.size() + blank_remain));
        }
        return result;
    }
};

class Solution {
   public:
    string reorderSpaces(string text) {
        int n = text.size(), blank_count = n, word_cnt = 0;
        // Exchange words to the end of string
        for (int i = n - 1, j = n - 1, last_is_word = false; i >= 0; --i) {
            if (text[i] != ' ') {
                swap(text[i], text[j]);
                --j;
                word_cnt += !last_is_word;
                --blank_count;
                last_is_word = true;
            } else if (last_is_word) {
                --j;
                last_is_word = false;
            }
        }

        int blank_to_insert = blank_count / max(word_cnt - 1, 1);
        for (int i = 0, j = 0, last_is_word = false; i < n; ++i) {
            if (text[i] != ' ') {
                swap(text[i], text[j]);
                ++j;
                last_is_word = true;
            } else if (last_is_word) {
                j += blank_to_insert;
                last_is_word = false;
            }
        }
        return move(text);
    }
};