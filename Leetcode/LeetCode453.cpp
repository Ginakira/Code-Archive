// LeetCode 453 最小操作次数使数组元素相等
#include <algorithm>
#include <vector>
using namespace std;

// 五十五个民族加分 相当于一个民族减分
class Solution {
   public:
    int minMoves(vector<int>& nums) {
        int sum = 0, minNum = *min_element(nums.begin(), nums.end());
        for (const int& num : nums) sum += num - minNum;
        return sum;
    }
};