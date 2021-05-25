// 剑指 Offer 10- II. 青蛙跳台阶问题
#include <vector>
using namespace std;
class Solution {
    const int MOD = 1000000007;

   public:
    int numWays(int n) {
        static vector<int> mem(101, -1);
        if (mem[n] == -1) {
            if (n == 0) {
                mem[0] = 1;
            } else if (n <= 3) {
                mem[n] = n;
            } else {
                mem[n] = (numWays(n - 1) + numWays(n - 2)) % MOD;
            }
        }
        return mem[n];
    }
};