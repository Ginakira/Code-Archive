// LeetCode 2255 统计是给定字符串前缀的字符串数目

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
   private:
    bool isPrefix(const string& s, const string& pattern) {
        if (pattern.size() > s.size()) {
            return false;
        }
        int n = pattern.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] != pattern[i]) {
                return false;
            }
        }
        return true;
    }

   public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for (const auto& word : words) {
            cnt += isPrefix(s, word);
        }
        return cnt;
    }
};