// LeetCode 1252 奇数值单元格的数目

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int> row_cnt(m), col_cnt(n);
        for (auto& indice : indices) {
            ++row_cnt[indice[0]];
            ++col_cnt[indice[1]];
        }

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((row_cnt[i] + col_cnt[j]) & 1) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};