// LeetCode 2180 统计各位数字之和为偶数的整数个数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countEven(int num) {
        int count = 0;
        for (int i = 1; i <= num; ++i) {
            int x = i, sum = 0;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            count += !(sum & 1);
        }
        return count;
    }
};