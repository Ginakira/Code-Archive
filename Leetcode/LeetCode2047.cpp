// LeetCode 2047 句子中的有效单词数

#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countValidWords(string sentence) {
        stringstream ss(sentence);
        string temp;
        vector<string> words;
        while (ss >> temp) {
            words.emplace_back(temp);
        }

        return count_if(words.begin(), words.end(), [](auto &word) {
            bool has_hyphen = false, has_symbol = false;
            for (size_t i = 0, n = word.size(); i < n; ++i) {
                char c = word[i];
                if (isdigit(c)) return false;
                if (!isalpha(c) && c != '-' && c != ',' && c != '.' && c != '!')
                    return false;
                if (c == '-') {
                    if (!(!has_hyphen && i > 0 && islower(word[i - 1]) &&
                          i < n - 1 && islower(word[i + 1]))) {
                        return false;
                    }
                    has_hyphen = true;
                } else if (c == '.' || c == ',' || c == '!') {
                    if (has_symbol || i != n - 1) return false;
                    has_symbol = true;
                }
            }
            return true;
        });
    }
};