// LeetCode 476 数字的补数

// 异或一个与其位数相等 二进制表示下全是1的数即可
class Solution {
   public:
    int findComplement(int num) {
        int base = 1;
        while (base < num) {
            base <<= 1;
            ++base;
        }
        return base ^ num;
    }
};