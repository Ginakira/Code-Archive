// LeetCode 2221 数组的三角和

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
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j > i; --j) {
                nums[j] = (nums[j] + nums[j - 1]) % 10;
            }
        }
        return nums.back();
    }
};