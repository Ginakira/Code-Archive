#include <vector>
using namespace std;

// Solution1: 贪心法
// 先翻转行，将所有行的第一位全都变为1
// 再翻转列(除第一列)，保证每一列的1尽可能多
class Solution {
   public:
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        for (int i = 0; i < n; ++i) {
            if (A[i][0]) continue;
            for (int j = 0; j < m; ++j) {
                A[i][j] = !A[i][j];
            }
        }
        for (int j = 1; j < m; ++j) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (A[i][j]) ++sum;
            }
            if (sum < n - sum) {
                for (int i = 0; i < n; ++i) {
                    A[i][j] = !A[i][j];
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (A[i][j]) ret += 1 << (m - j - 1);
            }
        }
        return ret;
    }
};