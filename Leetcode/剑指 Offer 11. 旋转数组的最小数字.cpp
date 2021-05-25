// 剑指 Offer 11. 旋转数组的最小数字
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 同LC154
class Solution {
   public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int left = 0, right = n - 1, mid;
        while (left < right) {
            mid = (left + right) >> 1;
            if (numbers[mid] < numbers[right]) {
                right = mid;
            } else if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else {
                --right;
            }
        }
        return numbers[left];
    }
};