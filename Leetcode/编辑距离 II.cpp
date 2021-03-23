// 编辑距离II
/*
给你两个单词 s 和 t，请你计算出将 s 转换成 t 所使用的最少操作数。

你可以对一个单词进行如下两种操作：

删除一个字符
替换一个字符
注意：

不允许插入操作
题目保证有解
示例：


输入：s = "abcdefg", t = "abdde"
输出：3
提示：

1 <= len(s), len(t) <= 200

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/high-frequency-algorithm-exercise/omxcgt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <string>
#include <vector>
using namespace std;

// 注意当s串不足以再删除的情况！（也就是说s串如果再进行删除操作长度将会比t串更小）
class Solution {
   public:
    int edit_distance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0x3f3f3f3f));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, m); ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (i == j) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n][m];
    }
};