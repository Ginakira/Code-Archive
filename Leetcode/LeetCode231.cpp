// LeetCode 231 2的幂

class Solution {
   public:
    bool isPowerOfTwo(int n) { return (n > 0 && (n & (n - 1)) == 0); }
};