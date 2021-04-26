// LeetCode 1101 二分判定
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

// 二分判定
class Solution {
   private:
    bool check(vector<int> &weights, int days, int capacity) {
        int current_days = 1, today_remain = capacity;
        for (int &weight : weights) {
            if (today_remain < weight) {
                ++current_days;
                today_remain = capacity;
            }
            today_remain -= weight;
        }
        return current_days <= days;
    }

   public:
    int shipWithinDays(vector<int> &weights, int D) {
        int left = *max_element(weights.begin(), weights.end()),
            right = accumulate(weights.begin(), weights.end(), 0), mid;
        while (left < right) {
            mid = (left + right) >> 1;
            if (check(weights, D, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};