// LeetCode 204 计数质数

// Solution1: 线性筛法 104ms 27.7MB
class Solution {
   public:
    int prime[5000005] = {0};

    int countPrimes(int n) {
        for (int i = 2; i < n; ++i) {
            if (!prime[i]) prime[++prime[0]] = i;
            for (int j = 1; j <= prime[0]; ++j) {
                if (i * prime[j] >= n) break;
                prime[prime[j] * i] = 1;
                if (!(i % prime[j])) break;
            }
        }
        return prime[0];
    }
};