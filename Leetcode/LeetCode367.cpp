// LeetCode 367 有效的完全平方数

// 二分
class Solution {
   public:
    bool isPerfectSquare(int num) {
        long long left = 1, right = num;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long sum = mid * mid;
            if (sum == num) {
                return true;
            } else if (sum < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
};

// 利用完全平方数性质
// 完全平方数可以通过奇数累加得到，所以不断减去奇数，最后判断剩余的数字是否等于零即可
class Solution2 {
   public:
    bool isPerfectSquare(int num) {
        int num1 = 1;
        while (num > 0) {
            num -= num1;
            num1 += 2;
        }
        return num == 0;
    }
};