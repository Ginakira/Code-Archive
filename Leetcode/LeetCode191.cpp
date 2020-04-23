// 二进制中1的个数
#include <cinttypes>

class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t flag = 1;
        while (flag) {
            if (flag & n) count++;
            flag <<= 1;
        }
        return count;
    }
};