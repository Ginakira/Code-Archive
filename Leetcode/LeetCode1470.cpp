// LeetCode 1470 重新排列数组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res(2 * n);
        for (int i = 0, j = n, k = 0; i < n; ++i, ++j) {
            res[k++] = nums[i];
            res[k++] = nums[j];
        }
        return res;
    }
};