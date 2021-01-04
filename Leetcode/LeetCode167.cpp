// LeetCode 167 两数之和II-输入有序数组
#include <vector>
using namespace std;

// 8ms 双指针法
class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) break;
            sum < target ? ++left : --right;
        }
        return vector<int>{left + 1, right + 1};
    }
};