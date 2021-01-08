// LeetCode 326 3的幂
#include <cmath>
using namespace std;

// 循环
class Solution {
   public:
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }
};

// 换底
class Solution2 {
   public:
    bool isPowerOfThree(int n) {
        if (n == 0) return false;
        double x = log10(n) / log10(3);
        return x == floor(x);
    }
};