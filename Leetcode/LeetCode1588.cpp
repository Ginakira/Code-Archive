// LeetCode 1588 所有奇数长度子数组的和

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> pre_sum(n + 1);
        for (int i = 1; i <= n; ++i) {
            pre_sum[i] = pre_sum[i - 1] + arr[i - 1];
        }
        int sum = 0;
        for (int len = 1; len <= n; len += 2) {
            for (int i = len; i <= n; ++i) {
                sum += pre_sum[i] - pre_sum[i - len];
            }
        }
        return sum;
    }
};