// LeetCode 50 Pow(x, n)

// 递归快速幂
// 假如我们要计算x^13，它可以被分解为
// 2^0 -> 2^1 -> 2^3 -> 2^6 ->x^13
// 我们只需要计算x/2次幂 就能计算出x次幂的结果
// 如果x是奇数，那么结果就是x/2次幂平方再乘上基数，如果是偶数，就是平方
class Solution {
   public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickPow(x, N) : 1.0 / quickPow(x, -N);
    }

    double quickPow(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double result = quickPow(x, N / 2);
        return N % 2 == 0 ? result * result : result * result * x;
    }
};