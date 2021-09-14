// LeetCode 524 通过删除字幕匹配到字典里最长单词

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 排序 + 暴力双指针匹配
class Solution {
   private:
    bool check(const string &target, const string &s) {
        int n = target.size(), m = s.size();
        if (n > m) return false;
        int pa = 0, pb = 0;
        while (pa < n && pb < m) {
            while (pb < m && target[pa] != s[pb]) ++pb;
            if (pb >= m) break;
            ++pa, ++pb;
        }
        return pa == n;
    }

   public:
    string findLongestWord(string s, vector<string> &dictionary) {
        sort(dictionary.begin(), dictionary.end(),
             [](const string &a, const string &b) {
                 return a.size() == b.size() ? a < b : a.size() > b.size();
             });

        for (auto &word : dictionary) {
            if (check(word, s)) {
                return word;
            }
        }

        return {};
    }
};