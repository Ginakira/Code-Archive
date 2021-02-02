// ByteDance 春招冲刺班 内部试题

// DNA 是由 ACGT 四种核苷酸组成，例如 AAAGTCTGAC，假定自然环境下 DNA
// 发生异变的情况有：

// 基因缺失一个核苷酸
// 基因新增一个核苷酸
// 基因替换一个核苷酸
// 且发生概率相同。
// 古生物学家 Sam 得到了若干条相似 DNA 序列，Sam 认为一个 DNA 序列向另外一个 DNA
// 序列转变所需的最小异变情况数可以代表其物种血缘相近程度，异变情况数越少，血缘越相近，请帮助
// Sam 实现获取两条 DNA 序列的最小异变情况数的算法。

// 输入描述:

// 每个样例只有一行，两个 DNA 序列字符串以英文逗号“,”分割
// 输出描述:
// 输出转变所需的最少情况数，类型是数字

// 测试用例:
// 输入
// ACT,AGCT
// 输出
// 1

// 数据范围：

// 每个 DNA 序列不超过 100 个字符

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s, s1, s2;
    cin >> s;
    stringstream ss(s);
    getline(ss, s1, ',');
    getline(ss, s2, ',');
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int left = dp[i - 1][j] + 1;
            int down = dp[i][j - 1] + 1;
            int left_down = dp[i - 1][j - 1];
            if (s1[i - 1] != s2[j - 1]) {
                ++left_down;
            }
            dp[i][j] = min(left, min(down, left_down));
        }
    }
    cout << dp[n][m];
    return 0;
}