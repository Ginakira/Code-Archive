// 和为s的连续正数序列
#include <vector>
using namespace std;

// 枚举 + 暴力 20ms
class Solution {
   public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        for (int i = 1; i <= target / 2; ++i) {
            int sum = 0;
            for (int j = i; sum < target && j < target; ++j) {
                sum += j, tmp.push_back(j);
            }
            if (sum == target) {
                ans.push_back(tmp);
            }
            tmp.clear();
        }
        return ans;
    }
};

// 滑动窗口法 0ms
class Solution2 {
   public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int sum = 0, left = 1, right = 1;
        while (left <= target / 2) {
            if (sum < target) {
                sum += right, right++;
            } else if (sum > target) {
                sum -= left, left++;
            } else {
                for (int i = left; i < right; ++i) {
                    tmp.push_back(i);
                }
                ans.push_back(tmp);
                tmp.clear();
                sum -= left, left++;
            }
        }
        return ans;
    }
};