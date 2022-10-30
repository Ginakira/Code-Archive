// LeetCode 784 字母大小写全排列

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    size_t n_;

    void dfs(string &s, int pos, vector<string> &ans) {
        while (pos < n_ && isdigit(s[pos])) {
            ++pos;
        }
        if (pos == n_) {
            ans.emplace_back(s);
            return;
        }
        s[pos] ^=
            32;  // Interesting.
                 // 因为大小写恰好相差32，32正好只有一位是1，所以用异或运算恰好可以达到切换大小写的效果。
        dfs(s, pos + 1, ans);
        s[pos] ^= 32;
        dfs(s, pos + 1, ans);
        return;
    }

   public:
    vector<string> letterCasePermutation(string s) {
        n_ = s.size();
        vector<string> ans;
        dfs(s, 0, ans);
        return ans;
    }
};