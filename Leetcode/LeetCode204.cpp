// LeetCode 204 计数质数
#include <vector>
using namespace std;

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

// C++写法优化内存占用 220ms 9.5MB
class Solution2 {
   public:
    int countPrimes(int n) {
        vector<int> primes;
        vector<bool> is_prime(n, 1);
        for (int i = 2; i < n; ++i) {
            if (is_prime[i]) primes.push_back(i);
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
                is_prime[primes[j] * i] = false;
                if (!(i % primes[j])) break;
            }
        }
        return primes.size();
    }
};