// LeetCode 633 平方数之和
#include <cmath>
using namespace std;

// 暴力枚举
class Solution {
   public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; ++a) {
            double b = sqrt(c - a * a);
            if (b == (int)b) return true;
        }
        return false;
    }
};

// 双指针
class Solution2 {
   public:
    bool judgeSquareSum(int c) {
        long left = 0, right = (int)sqrt(c);
        while (left <= right) {
            long sum = left * left + right * right;
            if (sum == c) {
                return true;
            } else if (sum < c) {
                ++left;
            } else {
                --right;
            }
        }
        return false;
    }
};

class Solution3 {
   public:
    bool judgeSquareSum(int c) {
        int a = 0, b = sqrt(c);
        while (a <= b) {
            auto res = a * a <=> c - b * b;
            if (res < 0) {
                ++a;
            } else if (res > 0) {
                --b;
            } else {
                return true;
            }
        }
        return false;
    }
};