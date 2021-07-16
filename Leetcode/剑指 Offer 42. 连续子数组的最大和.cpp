// 剑指 Offer 42. 连续子数组的最大和
#include <algorithm>
#include <climits>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 同LC53
class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        for (const int& num : nums) {
            sum = max(sum + num, num);
            ans = max(ans, sum);
        }
        return ans;
    }
};