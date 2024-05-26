// LeetCode 1738 找出第K大的异或坐标值
#include <algorithm>
#include <priority_queue>
#include <queue>
#include <vector>
using namespace std;

// 二维前缀和 + 小顶堆
class Solution2 {
   public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> pre_xor(n + 1, vector<int>(m + 1, 0));
        priority_queue<int, vector<int>, greater<int>> q;
        for (int j = 1; j <= m; ++j) {
            for (int i = 1; i <= n; ++i) {
                pre_xor[i][j] = pre_xor[i - 1][j] ^ pre_xor[i][j - 1] ^
                                pre_xor[i - 1][j - 1] ^ matrix[i - 1][j - 1];
                if (q.size() < k || q.top() < pre_xor[i][j]) {
                    q.push(pre_xor[i][j]);
                }
                if (q.size() > k) {
                    q.pop();
                }
            }
        }
        return q.top();
    }
};

// 二维前缀和 + 快速选择
class Solution {
   public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> pre_xor(m + 1, vector<int>(n + 1));
        vector<int> results;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                pre_xor[i][j] = pre_xor[i][j - 1] ^ pre_xor[i - 1][j] ^
                                pre_xor[i - 1][j - 1] ^ matrix[i - 1][j - 1];
                results.emplace_back(pre_xor[i][j]);
            }
        }
        nth_element(results.begin(), results.begin() + k - 1, results.end(),
                    greater<int>());
        return *(results.begin() + k - 1);
    }
};