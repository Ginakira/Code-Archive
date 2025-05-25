// LeetCode 2131 连接两字母单词得到的最长回文串

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestPalindrome(vector<string>& words) {
        int ans = 0;
        bool mid_palindrome_flag = false;
        unordered_map<string, int> freq;
        for (const auto& word : words) {
            ++freq[word];
        }
        for (const auto& [word, cnt] : freq) {
            string rev = string(1, word[1]) + word[0];
            if (word == rev) {
                if (cnt & 1) {
                    mid_palindrome_flag = true;
                }
                ans += 2 * (cnt / 2 * 2);
            } else if (word > rev) {
                ans += 4 * min(cnt, freq[rev]);
            }
        }
        if (mid_palindrome_flag) {
            ans += 2;
        }
        return ans;
    }
};