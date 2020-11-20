// LeetCode 7 整数反转
#include <climits>
using namespace std;

class Solution {
   public:
    int reverse(int x) {
        long long ans = 0;
        while (x) {
            ans = ans * 10 + x % 10;
            if (ans < INT_MIN || ans > INT_MAX) return 0;
            x /= 10;
        }
        return ans;
    }
};

// 题中要求只能使用32位有符号整数
class Solution2 {
   public:
    int reverse(int x) {
        int ans = 0;
        const int INT_MAX_MOD_TEN = INT_MAX % 10,
                  INT_MAX_DIV_TEN = INT_MAX / 10;
        const int INT_MIN_MOD_TEN = INT_MIN % 10,
                  INT_MIN_DIV_TEN = INT_MIN / 10;
        while (x) {
            int temp = x % 10;
            if (ans > INT_MAX_DIV_TEN ||
                (ans == INT_MAX_DIV_TEN && temp > INT_MAX_MOD_TEN))
                return 0;
            if (ans < INT_MIN_DIV_TEN ||
                (ans == INT_MIN_DIV_TEN && temp < INT_MIN_MOD_TEN))
                return 0;
            ans = ans * 10 + temp;
            x /= 10;
        }
        return ans;
    }
};