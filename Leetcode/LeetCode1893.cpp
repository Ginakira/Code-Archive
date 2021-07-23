// LeetCode 1893 检查是否区域内所有整数都被覆盖

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 暴力
class Solution {
   public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for (int i = left; i <= right; ++i) {
            int included = false;
            for (auto& range : ranges) {
                int start = range[0], end = range[1];
                if (i >= start && i <= end) {
                    included = true;
                    break;
                }
            }
            if (!included) return false;
        }
        return true;
    }
};

// 利用差分数组维护区间问题

class Solution2 {
   public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(55);
        // diff存储的是对应的数字被覆盖次数的差分结果，数字题目中规定的范围是50以内
        for (auto& range : ranges) {
            ++diff[range[0]];
            --diff[range[1] + 1];
        }

        int curr = 0;
        for (int i = 1; i <= 50; ++i) {
            curr += diff[i];
            if (i >= left && i <= right && curr <= 0) {
                return false;
            }
        }
        return true;
    }
};