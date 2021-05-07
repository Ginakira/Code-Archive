// LeetCode 1486 数组异或操作

class Solution {
   public:
    int xorOperation(int n, int start) {
        int result = 0;
        for (int i = start, end = start + (n - 1) * 2; i <= end; i += 2) {
            result ^= i;
        }
        return result;
    }
};