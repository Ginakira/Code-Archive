// LeetCode 661 图片平滑器

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    size_t n_;
    size_t m_;

    int cal_avg(vector<vector<int>>& img, int x, int y) {
        int count = 0;
        double sum = 0;
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                int tx = x + i, ty = y + j;
                if (tx < 0 || tx >= n_ || ty < 0 || ty >= m_) {
                    continue;
                }
                ++count;
                sum += img[tx][ty];
            }
        }
        return floor(sum / count);
    }

   public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        n_ = img.size();
        m_ = img[0].size();

        vector<vector<int>> result(n_, vector<int>(m_));
        for (int i = 0; i < n_; ++i) {
            for (int j = 0; j < m_; ++j) {
                result[i][j] = cal_avg(img, i, j);
            }
        }
        return result;
    }
};

class Solution2 {
   public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                sum[i][j] = img[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] -
                            sum[i - 1][j - 1];
            }
        }

        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int a = max(0, i - 1);      // up
                int b = max(0, j - 1);      // left
                int c = min(n - 1, i + 1);  // down
                int d = min(m - 1, j + 1);  // right
                int cnt = (c - a + 1) * (d - b + 1);
                int total = sum[c + 1][d + 1] - sum[a][d + 1] - sum[c + 1][b] +
                            sum[a][b];
                ans[i][j] = total / cnt;
            }
        }
        return ans;
    }
};