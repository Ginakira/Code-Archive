// LeetCode 74 搜索二维矩阵
#include <vector>
using namespace std;

// 两次二分搜索
class Solution {
   private:
    int n, m;

    int search_row(vector<vector<int>> &matrix, int target) {
        int left = 0, right = n - 1, mid;
        while (left < right) {
            mid = (left + right + 1) >> 1;
            if (matrix[mid][0] <= target) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    bool search_col(vector<vector<int>> &matrix, int target, int row) {
        int left = 0, right = m - 1, mid;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }

   public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        n = matrix.size(), m = matrix[0].size();
        int target_row = search_row(matrix, target);
        return search_col(matrix, target, target_row);
    }
};