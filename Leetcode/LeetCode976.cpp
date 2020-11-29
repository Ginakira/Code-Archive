// LeetCode 976 三角形的最大周长
#include <algorithm>
#include <vector>
using namespace std;

// 排序 + 贪心
// 因为要的是最大周长，所以排序后先从大边开始判断相邻的三条边，第一个满足的即为最大的
class Solution {
   public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        for (int i = A.size() - 1; i >= 2; --i) {
            if (A[i] < A[i - 2] + A[i - 1]) {
                return A[i] + A[i - 1] + A[i - 2];
            }
        }
        return 0;
    }
};