// LeetCode 500 键盘行
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 哈希表 0ms
class Solution {
   private:
    unordered_map<char, int> keyMap = {
        {'q', 1}, {'w', 1}, {'e', 1}, {'r', 1}, {'t', 1}, {'y', 1}, {'u', 1},
        {'i', 1}, {'o', 1}, {'p', 1}, {'Q', 1}, {'W', 1}, {'E', 1}, {'R', 1},
        {'T', 1}, {'Y', 1}, {'U', 1}, {'I', 1}, {'O', 1}, {'P', 1}, {'a', 2},
        {'s', 2}, {'d', 2}, {'f', 2}, {'g', 2}, {'h', 2}, {'j', 2}, {'k', 2},
        {'l', 2}, {'A', 2}, {'S', 2}, {'D', 2}, {'F', 2}, {'G', 2}, {'H', 2},
        {'J', 2}, {'K', 2}, {'L', 2}, {'z', 3}, {'x', 3}, {'c', 3}, {'v', 3},
        {'b', 3}, {'n', 3}, {'m', 3}, {'Z', 3}, {'X', 3}, {'C', 3}, {'V', 3},
        {'B', 3}, {'N', 3}, {'M', 3},
    };

   public:
    vector<string> findWords(vector<string> &words) {
        vector<string> ret;
        for (auto &word : words) {
            if (check(word)) ret.emplace_back(word);
        }
        return ret;
    }

    bool check(string &word) {
        int base = keyMap[word[0]];
        for (int i = 1; i < word.size(); ++i) {
            if (keyMap[word[i]] != base) return false;
        }
        return true;
    }
};

// 数组 4ms
class Solution2 {
   private:
    int keyMap[26] = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3,
                      3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};

   public:
    vector<string> findWords(vector<string> &words) {
        vector<string> ret;
        for (auto &word : words) {
            if (check(word)) ret.emplace_back(word);
        }
        return ret;
    }

    bool check(string &word) {
        int base = keyMap[tolower(word[0]) - 'a'];
        for (int i = 1; i < word.size(); ++i) {
            if (keyMap[tolower(word[i]) - 'a'] != base) return false;
        }
        return true;
    }
};