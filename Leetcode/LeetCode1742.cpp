// LeetCode 1742 盒子中小球的最大数量

#include <algorithm>
#include <array>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int cal_digit_sum(int id) {
        int sum = 0;
        while (id) {
            sum += id % 10;
            id /= 10;
        }
        return sum;
    }

   public:
    int countBalls(int lowLimit, int highLimit) {
        array<int, 46> cnt{0};
        int max_cnt = 0;
        for (int i = lowLimit; i <= highLimit; ++i) {
            int sum = cal_digit_sum(i);
            ++cnt[sum];
            max_cnt = max(max_cnt, cnt[sum]);
        }
        return max_cnt;
    }
};