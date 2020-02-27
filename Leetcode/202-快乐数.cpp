#include <cmath>
#include <cstring>

class Solution {
   public:
    long long cal(long long x) {
        long long ans = 0;
        while (x != 0) {
            ans += pow(x % 10, 2);
            x /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        bool mark[1000];
        memset(mark, false, sizeof(mark));
        while (n != 1) {
            n = cal(n);
            if (mark[n]) return false;
            mark[n] = true;
        }
        return true;
    }
};

//解法2: 快慢指针思想 与判断链表是否有环相同
/*
    此种计算方法必定会产生循环，只有两种情况：
    1. 循环结果为1
    2. 循环不到1，即为题中所说无限循环
    所以使用快慢指针思想，每次循环慢指针计算一次，快指针计算两次
    如果二者相等，即为循环，如果是因为1产生的循环，则true
*/
class Solution2 {
   public:
    int bitSquareNum(int num) {
        int sum = 0;
        while (num) {
            int bit = num % 10;
            sum += bit * bit;
            num /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = bitSquareNum(slow);
            fast = bitSquareNum(fast);
            fast = bitSquareNum(fast);
        } while (slow != fast);
        return slow == 1;
    }
};