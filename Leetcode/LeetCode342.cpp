// LeetCode 342 4的幂

// 循环
class Solution {
   public:
    bool isPowerOfFour(int n) {
        if (n == 0) return false;
        while (n % 4 == 0) n /= 4;
        return n == 1;
    }
};

// 位运算
class Solution2 {
   public:
    bool isPowerOfFour(int n) {
        return (n > 0) && !(n & (n - 1)) && (n & 0x55555555);
    }
};