// LeetCode 2684 矩阵中移动的最大次数

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
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        unordered_set<int> q, q2;
        for (int i = 0; i < n; ++i) {
            q.emplace(i);
        }
        for (int j = 1; j < m; ++j) {
            q2.clear();
            for (int i : q) {
                for (int ni = i - 1; ni <= i + 1; ++ni) {
                    if (ni < 0 || ni >= n || grid[i][j - 1] >= grid[ni][j]) {
                        continue;
                    }
                    q2.emplace(ni);
                }
            }
            swap(q, q2);
            if (q.empty()) {
                return j - 1;
            }
        }
        return m - 1;
    }
};