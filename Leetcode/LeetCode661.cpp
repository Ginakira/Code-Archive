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