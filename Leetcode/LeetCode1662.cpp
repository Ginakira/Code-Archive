// LeetCode 1662 检查两个字符串数组是否相等

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = accumulate(word1.begin(), word1.end(), string());
        string s2 = accumulate(word2.begin(), word2.end(), string());
        return s1 == s2;
    }
};