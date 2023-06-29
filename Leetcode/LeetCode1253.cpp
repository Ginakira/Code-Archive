// LeetCode 1253 重构2行二进制矩阵

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
   public:
    vector<vector<int>> reconstructMatrix(int upper, int lower,
                                          vector<int>& colsum) {
        int n = colsum.size();
        int sum = 0, two_cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                ++two_cnt;
            }
            sum += colsum[i];
        }
        if (sum != upper + lower || min(upper, lower) < two_cnt) {
            return {};
        }
        upper -= two_cnt;
        lower -= two_cnt;
        vector<vector<int>> ans(2, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                ans[0][i] = ans[1][i] = 1;
            } else if (colsum[i] == 1) {
                if (upper > lower) {
                    ans[0][i] = 1;
                    --upper;
                } else {
                    ans[1][i] = 1;
                    --lower;
                }
            }
        }
        return ans;
    }
};