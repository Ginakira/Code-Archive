// 剑指 Offer 16. 数值的整数次方
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 递归快速幂 迭代见LC50
class Solution {
   private:
    double quick_pow(double x, long long n) {
        if (n == 0) {
            return 1;
        }
        double y = quick_pow(x, n / 2);
        return n & 1 ? y * y * x : y * y;
    }

   public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quick_pow(x, N) : 1.0 / quick_pow(x, -N);
    }
};