// LeetCode 507 完美数
#include <cmath>
using namespace std;

// 因子成对出现 0ms
class Solution {
   public:
    bool checkPerfectNumber(int num) {
        int sum = 1, sqr = (int)ceil(sqrt(num));
        for (int i = 2; i < sqr; ++i) {
            if (num % i == 0) {
                sum += i + num / i;
            }
        }
        sum += sqr * sqr == num ? sqr : 0;

        return sum == num;
    }
};