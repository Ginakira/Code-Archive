// LeetCode 1822 数组元素积的符号

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (int num : nums) {
            if (num == 0) {
                return 0;
            } else if (num < 0) {
                sign *= -1;
            }
        }
        return sign;
    }
};