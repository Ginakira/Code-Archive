// LeetCode 1175 质数排列

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    static constexpr int MOD = 1e9 + 7;
    uint64_t frac(int n) {
        if (n == 0 || n == 1) return 1;
        return n * frac(n - 1) % MOD;
    }

   public:
    int numPrimeArrangements(int n) {
        int prime_count = 0;
        for (int i = 2; i <= n; ++i) {
            bool is_prime = true;
            for (int j = 2; j * j <= i; ++j) {
                if (i % j == 0) {
                    is_prime = false;
                    break;
                }
            }
            prime_count += (int)is_prime;
        }
        return frac(prime_count) * frac(n - prime_count) % MOD;
    }
};