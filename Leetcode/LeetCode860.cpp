// LeetCode 860 柠檬水找零
#include <vector>
using namespace std;

// Solution1: 贪心
// 记录收到的钱数，每次优先从大面额的钱开始找零
class Solution {
   public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt[3] = {0};
        for (const int& bill : bills) {
            switch (bill) {
                case 5:
                    ++cnt[0];
                    break;
                case 10:
                    ++cnt[1];
                    break;
                case 20:
                    ++cnt[2];
                    break;
            }
            int change = bill - 5;
            for (int i = 2; i >= 0; --i) {
                if (change <= 0 || cnt[i] <= 0) continue;
                int base = 5 * (1 << i);
                int temp = cnt[i] * base <= change ? cnt[i] : change / base;
                cnt[i] -= temp, change -= base * temp;
            }
            if (change > 0) return false;
        }
        return true;
    }
};