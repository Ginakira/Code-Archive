// LeetCode 1074 元素和为目标值的子矩阵数量

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 前缀和 + 哈希表
// 思路与LC560相仿，枚举每一个边界，我们可以分别枚举其上下边界，去计算出每一列的元素之和，再用LC560的思路，对这个一维的列元素之和利用前缀和+哈希表求解，相当于枚举了左右边界
class Solution {
   private:
    int sumSubArray(vector<int> &sum, int target) {
        unordered_map<int, int> count;
        int ans = 0, pre = 0;
        count[0] = 1;
        for (int &num : sum) {
            pre += num;
            if (count.find(pre - target) != count.end()) {
                ans += count[pre - target];
            }
            ++count[pre];
        }
        return ans;
    }

   public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {  // 枚举上边界
            vector<int> sum(m);
            for (int j = i; j < n; ++j) {  // 枚举下边界
                for (int k = 0; k < m; ++k) {
                    sum[k] += matrix[j][k];
                }
                ans += sumSubArray(sum, target);
            }
        }
        return ans;
    }
};