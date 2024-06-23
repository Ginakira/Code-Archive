// LeetCode 520 检测大写字母
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

class Solution {
   public:
    bool detectCapitalUse(string word) {
        int lowerCnt = 0, upperCnt = 0, n = word.size();
        for (const char &c : word) {
            if (islower(c)) {
                ++lowerCnt;
            } else {
                ++upperCnt;
            }
        }
        if (lowerCnt == n || upperCnt == n) return true;
        return upperCnt == 1 && isupper(word[0]);
    }
};

class Solution2 {
   public:
    bool detectCapitalUse(string word) {
        return (all_of(word.begin(), word.end(),
                       [](char ch) { return (bool)islower(ch); }) ||
                all_of(word.begin(), word.end(),
                       [](char ch) { return (bool)isupper(ch); }) ||
                (isupper(word[0]) &&
                 all_of(word.begin() + 1, word.end(),
                        [](char ch) { return (bool)islower(ch); })));
    }
};


class Solution3 {
public:
    bool detectCapitalUse(string word) {
        std::array<function<bool(const std::string &)>, 3> filters = {
            [](const std::string &word) -> bool {
                return ranges::all_of(word, ::isupper);
            },
            [](const std::string &word) -> bool{
                return ranges::all_of(word, ::islower);
            },
            [](const std::string &word) -> bool {
                return std::isupper(word[0]) && ranges::all_of(word.substr(1), ::islower);
            },
        };
        for (auto &filter : filters) {
            if (filter(word)) {
                return true;
            }
        }
        return false;
    }
};