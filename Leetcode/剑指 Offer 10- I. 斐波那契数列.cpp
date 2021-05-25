// 剑指 Offer 10- I. 斐波那契数列
#include <vector>
using namespace std;

class Solution {
   private:
    const int MOD = 1000000007;

   public:
    int fib(int n) {
        static vector<int> mem(101, -1);
        if (mem[n] == -1) {
            if (n <= 1) {
                mem[n] = n;
            } else {
                mem[n] = (fib(n - 2) + fib(n - 1)) % MOD;
            }
        }
        return mem[n];
    }
};