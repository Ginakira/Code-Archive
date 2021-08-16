// LeetCode 5844 数组元素的最小非零乘积

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    static constexpr int MOD = 1e9 + 7;

    long long qpow(long long a, long long n) {
        long long ans = 1;
        while (n) {
            if (n & 1) {
                ans *= a;
                ans %= MOD;
            }
            a *= a;
            a %= MOD;
            n >>= 1;
        }
        return ans;
    }

   public:
    int minNonZeroProduct(int p) {
        // (2 ^ p - 1) * ((2 ^ p - 2) ^ (2 ^ (p - 1) - 1))
        long long n = ((1LL << p) - 1) % MOD;
        long long t = (1LL << (p - 1)) - 1;
        long long a = (1LL << p) % MOD - 2;
        long long x = qpow(a, t);
        long long mn = n * x % MOD;
        return mn;
    }
};