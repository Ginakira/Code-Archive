// LeetCode 832 翻转图像
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int rows = A.size(), cols = A[0].size();
        int mid = cols / 2 + cols % 2;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < mid; ++j) {
                if (!(A[i][j] ^ A[i][cols - j - 1])) {
                    A[i][j] = A[i][cols - j - 1] = !A[i][j];
                }
            }
        }
        return A;
    }
};