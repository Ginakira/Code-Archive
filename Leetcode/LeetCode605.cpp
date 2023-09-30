// LeetCode 605 种花问题
#include <vector>
using namespace std;

// Solution: 贪心
// 首位各添加一个0，简化边界判断
// 只要碰到连续的三个零，即当前位、前一位、后一位均为零，即可在当前位种一朵花
class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0;
        flowerbed.insert(flowerbed.begin(), 0);
        flowerbed.push_back(0);
        for (int i = 1; i < flowerbed.size() - 1; ++i) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 &&
                flowerbed[i + 1] == 0) {
                cnt++, flowerbed[i] = 1;
            }
        }
        return n <= cnt;
    }
};

class Solution2 {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; n > 0 && i < flowerbed.size();) {
            if (flowerbed[i]) {
                i += 2;
                continue;
            }
            if (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0) {
                --n;
                i += 2;
            } else {
                i += 3;
            }
        }
        return n <= 0;
    }
};