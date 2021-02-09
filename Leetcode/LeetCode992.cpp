// LeetCode 992 K个不同整数的子数组
#include <vector>
using namespace std;

class Solution {
   public:
    // 恰好有K个不同整数的子数组数 = 最多有K个不同整数的子数组数 - 最多有K -
    // 1个不同整数的子数组数 就像：有三个offer的人 = 有1或2或3个offer的人 -
    // 有1或2个offer的人
    int subarraysWithKDistinct(vector<int>& A, int K) {
        // _k为至多k个不同整数相关的变量  _j为至多k - 1个不同整数相关的变量
        int n = A.size();
        // 元素出现次数
        vector<int> freq_k(n + 1), freq_j(n + 1);
        // 当前[left, right)区间内不同整数的个数
        int count_k = 0, count_j = 0;
        int left_k = 0, left_j = 0, right = 0;
        int res_k = 0, res_j = 0;
        while (right < n) {
            int cur = A[right];
            if (freq_k[cur] == 0) {
                ++count_k;
            }
            if (freq_j[cur] == 0) {
                ++count_j;
            }
            freq_k[cur]++;
            freq_j[cur]++;
            ++right;

            while (count_k > K) {
                --freq_k[A[left_k]];
                if (freq_k[A[left_k]] == 0) {
                    --count_k;
                }
                ++left_k;
            }
            while (count_j > K - 1) {
                --freq_j[A[left_j]];
                if (freq_j[A[left_j]] == 0) {
                    --count_j;
                }
                ++left_j;
            }
            res_k += right - left_k;
            res_j += right - left_j;
        }
        return res_k - res_j;
    }
};