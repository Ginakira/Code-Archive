// LeetCode 3242 设计相邻元素求和服务

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

class NeighborSum {
   public:
    NeighborSum(vector<vector<int>>& grid) {
        n_ = grid.size();
        m_ = grid[0].size();
        for (int i = 0; i < n_; ++i) {
            for (int j = 0; j < m_; ++j) {
                update_sum_by_dirs(grid, adj_dirs, adj_sum_, i, j);
                update_sum_by_dirs(grid, dia_dirs, dia_sum_, i, j);
            }
        }
    }

    int adjacentSum(int value) { return adj_sum_[value]; }

    int diagonalSum(int value) { return dia_sum_[value]; }

   private:
    void update_sum_by_dirs(const vector<vector<int>>& grid,
                            const std::array<std::array<int, 2>, 4>& dirs,
                            unordered_map<int, int>& sum, int i, int j) {
        int num = grid[i][j];
        for (auto& [dx, dy] : dirs) {
            int tx = i + dx, ty = j + dy;
            if (tx < 0 || tx >= n_ || ty < 0 || ty >= m_) {
                continue;
            }
            sum[grid[tx][ty]] += num;
        }
    }

    static constexpr std::array<std::array<int, 2>, 4> adj_dirs = {{
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    }};
    static constexpr std::array<std::array<int, 2>, 4> dia_dirs = {{
        {1, 1},
        {1, -1},
        {-1, 1},
        {-1, -1},
    }};

    int n_;
    int m_;
    unordered_map<int, int> adj_sum_;
    unordered_map<int, int> dia_sum_;
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */