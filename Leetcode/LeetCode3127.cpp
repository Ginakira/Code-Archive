// LeetCode 3127 构造相同颜色的正方形

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
    bool canMakeSquare(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m - 1; ++j) {
                array<int, 2> cnt{{0}};
                for (int k = i; k < i + 2; ++k) {
                    for (int l = j; l < j + 2; ++l) {
                        ++cnt[grid[k][l] == 'W' ? 0 : 1];
                    }
                }
                if (cnt[0] <= 1 || cnt[1] <= 1) {
                    return true;
                }
            }
        }
        return false;
    }
};