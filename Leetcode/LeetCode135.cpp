// LeetCode 135 分发糖果
#include <vector>
using namespace std;

// Solution1: 两次遍历 取最大值累加
class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n, 1);
        for (int i = 0; i < n; ++i) {
            if (i > 0 && ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        int ret = 0, right = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (i < n - 1 && ratings[i] > ratings[i + 1]) {
                right++;
            } else {
                right = 1;
            }
            ret += max(left[i], right);
        }
        return ret;
    }
};