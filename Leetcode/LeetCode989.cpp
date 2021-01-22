// LeetCode 989 数组形式的整数加法
#include <algorithm>
#include <vector>
using namespace std;

// 模拟
class Solution {
   public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int n = A.size();
        vector<int> res;
        for (int i = n - 1; i >= 0 || K > 0; --i, K /= 10) {
            if (i >= 0) {
                K += A[i];
            }
            res.push_back(K % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};