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

// 二分法
class Solution2 {
   public:
    int arrangeCoins(int n) {
        int left = 1, right = n, mid;
        while (left < right) {
            mid = left + (right - left + 1) / 2;
            if ((long long)mid * (mid + 1) <= (long long)2 * n) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};