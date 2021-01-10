// LeetCode 441 排列硬币

class Solution {
   public:
    int arrangeCoins(int n) {
        int cnt = 1;
        while (n >= cnt) {
            n -= cnt++;
        }
        return cnt - 1;
    }
};