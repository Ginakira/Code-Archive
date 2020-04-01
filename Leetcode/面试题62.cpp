// 每日一题 圆圈中最后剩下的数字

// 约瑟夫环 反向推算
class Solution {
   public:
    int lastRemaining(int n, int m) {
        int pos = 0;
        for (int i = 2; i <= n; ++i) {
            pos = (pos + m) % i;
        }
        return pos;
    }
};