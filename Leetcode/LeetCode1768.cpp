// LeetCode 1768 交替合并字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        size_t n = word1.size(), m = word2.size(), ind1 = 0, ind2 = 0;
        string ans;
        ans.reserve(n + m);
        while (ind1 < n || ind2 < m) {
            if (ind1 < n) {
                ans.push_back(word1[ind1++]);
            }
            if (ind2 < m) {
                ans.push_back(word2[ind2++]);
            }
        }
        return ans;
    }
};