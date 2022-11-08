// LeetCode 1684 统计一致字符串的数目

#include <algorithm>
#include <array>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        array<bool, 26> mark{false};
        for (auto ch : allowed) {
            mark[ch - 'a'] = true;
        }
        return count_if(words.begin(), words.end(), [&mark](auto& word) {
            for (auto ch : word) {
                if (!mark[ch - 'a']) {
                    return false;
                }
            }
            return true;
        });
    }
};