// LeetCode 2535 数组元素和与数字和的绝对差

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int differenceOfSum(vector<int>& nums) {
        int ele_sum = 0, dig_sum = 0;
        auto sum_dig = [](int num) {
            int sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            return sum;
        };
        for (int num : nums) {
            ele_sum += num;
            dig_sum += sum_dig(num);
        }
        return abs(ele_sum - dig_sum);
    }
};