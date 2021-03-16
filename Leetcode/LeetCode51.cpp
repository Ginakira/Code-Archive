// LeetCode 51 N皇后

#include <string>
#include <vector>
using namespace std;

class Solution {
   private:
    vector<vector<string>> ans;
    vector<string> path;
    vector<int> col, main, sub;

   public:
    vector<vector<string>> solveNQueens(int n) {
        path.resize(n, string(n, '.'));
        col.resize(n);
        main.resize(2 * n - 1);
        sub.resize(2 * n - 1);

        dfs(0, n);
        return ans;
    }

    void dfs(int row, int n) {
        if (row == n) {
            ans.emplace_back(path);
            return;
        }

        for (int j = 0; j < n; ++j) {
            if (col[j] || main[row - j + n - 1] || sub[row + j]) {
                continue;
            }
            col[j] = true;
            main[row - j + n - 1] = true;
            sub[row + j] = true;
            path[row][j] = 'Q';
            dfs(row + 1, n);
            col[j] = false;
            main[row - j + n - 1] = false;
            sub[row + j] = false;
            path[row][j] = '.';
        }
    }
};