// LeetCode 461 汉明距离

// 先异或得到不同的位置 然后右移运算统计1的个数
class Solution {
   public:
    int hammingDistance(int x, int y) {
        int num = x ^ y, cnt = 0;
        while (num) {
            cnt += num & 1;
            num >>= 1;
        }
        return cnt;
    }
};

// Brian Kernighan 算法
class Solution2 {
   public:
    int hammingDistance(int x, int y) {
        int result = x ^ y, distance = 0;
        while (result) {
            result &= result - 1;
            ++distance;
        }
        return distance;
    }
};