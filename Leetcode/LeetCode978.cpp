// LeetCode 978 最长湍流子数组
#include <vector>
using namespace std;

class Solution {
   public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = 0, max_len = 1;
        while (right < n - 1) {
            if (left == right) {  // 窗口大小为1
                if (arr[right] ==
                    arr[right + 1]) {  // 如果与下一项相等 则左右需要同时移动
                    ++left;
                }
                ++right;
            } else if ((arr[right - 1] < arr[right] &&
                        arr[right] > arr[right + 1]) ||
                       (arr[right - 1] > arr[right] &&
                        arr[right] < arr[right + 1])) {  // 符合要求 移动右边界
                ++right;
            } else {  // 否则 从当前的边界重新开始计算窗口
                left = right;
            }
            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};