// LeetCode 1641 统计字典序元音字符串的数目

#include <algorithm>
#include <array>
#include <numeric>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    int countVowelStrings(int n) {
        std::array<int, 5> dp{1, 1, 1, 1, 1};
        // dp[i][j]: 长度为 i + 1 ，以第 j 个元音为结尾的字符串个数
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < 5; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};