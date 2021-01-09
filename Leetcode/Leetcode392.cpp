// LeetCode 392 判断子序列
#include <string>
#include <vector>
using namespace std;

// 双指针法 4ms
class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int ps = 0, pt = 0;
        int ns = s.size(), nt = t.size();
        while (ps < ns && pt < nt) {
            if (s[ps] == t[pt]) {
                ps++;
            }
            pt++;
        }
        return ps == ns;
    }
};

// 动态规划
// dp[i][j] 代表母串第i位开始字符'a' + j第一次出现的位置
class Solution2 {
   public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> f(m + 1, vector<int>(26, 0));
        // dp预处理
        for (int i = 0; i < 26; ++i) {
            f[m][i] = m;
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < 26; ++j) {
                if (t[i] == j + 'a') {
                    f[i][j] = i;
                } else {
                    f[i][j] = f[i + 1][j];
                }
            }
        }
        // 匹配
        for (int i = 0, ind = 0; i < n; ++i) {
            if (f[ind][s[i] - 'a'] == m) return false;
            ind = f[ind][s[i] - 'a'] + 1;
        }
        return true;
    }
};