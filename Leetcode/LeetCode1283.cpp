// LeetCode 1283 使结果不超过阈值的最小除数
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 二分判定
class Solution {
   private:
    bool check(vector<int> &nums, int threshold, double mod) {
        int sum = 0;
        for (const int &num : nums) {
            sum += ceil(num / mod);
            if (sum > threshold) return false;
        }
        return sum <= threshold;
    }

   public:
    int smallestDivisor(vector<int> &nums, int threshold) {
        int left = 1, right = *max_element(nums.begin(), nums.end()), mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (check(nums, threshold, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};