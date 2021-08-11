// 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> exchange(vector<int> &nums) {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            return (a & 1) == 1 && (b & 1) == 0;
        });
        return nums;
    }
};