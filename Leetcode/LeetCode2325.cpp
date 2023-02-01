// LeetCode 2325 解密消息

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> dict;
        char cur_ch = 'a';
        for (auto ch : key) {
            if (ch == ' ' || dict.count(ch) || dict.size() >= 26) {
                continue;
            }
            dict[ch] = cur_ch;
            ++cur_ch;
        }
        transform(message.begin(), message.end(), message.begin(),
                  [&](char ch) { return ch == ' ' ? ch : dict[ch]; });
        return message;
    }
};