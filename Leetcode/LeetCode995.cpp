// LeetCode 995 K连续位的最小翻转次数
#include <vector>
using namespace std;

// S1: 60ms 差分数组
// 利用差分数组的性质，对于第i位开始的K位的子数组翻转，只需更改差分数组diff[i]与diff[i+K]
// 根据贪心的原则，每一位是0的元素都必须保证一次且最多一次翻转，如果翻转范围超过数组范围则不合法
class Solution {
   public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        vector<int> diff(n + 1);
        // rev_count记录当前位需要翻转的次数 即到当前位为止的差分数组累加和
        int ans = 0, rev_count = 0;
        for (int i = 0; i < n; ++i) {
            rev_count += diff[i];
            if ((A[i] + rev_count) % 2 == 0) {
                if (i + K > n) {
                    return -1;
                }
                ++diff[i + K];
                ++rev_count;
                ++ans;
            }
        }
        return ans;
    }
};

// 由于数组元素只可能是0或1
// 所以直接在原数组上使用其他的值进行标记是否在i位上进行了翻转操作
// 将空间复杂度优化至O(1)

class Solution2 {
   public:
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int ans = 0, rev_count = 0;
        for (int i = 0; i < n; ++i) {
            if (i >= K && A[i - K] > 1) {
                --rev_count;
                A[i - K] -= 2;
            }
            if ((A[i] + rev_count) % 2 == 0) {
                if (i + K > n) {
                    return -1;
                }
                A[i] += 2;
                ++rev_count;
                ++ans;
            }
        }
        return ans;
    }
};