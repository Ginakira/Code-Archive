// LeetCode 665 非递减数列
#include <vector>
using namespace std;

// 遇到a[i] > a[i + 1] 需要进行处理, 要么a[i] 变小, 要么a[i + 1] 变大;
// 贪心思想 : 尽量使a[i] 变小, 因为a[i + 1] 变大, 会影响后面数组的判断;
// 当a[i] > a[i + 1] 时, 必然存在a[i] >= a[i - 1], 如果a[i - 1] >
// a[i+1],就需要使a[i + 1] 变大; 举例 : -1 4 2, 需要将4变小;
// - 1 4 - 2, 需要将 - 2变大;
// 其他情况都可以a[i] 变小

class Solution {
   public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                ++count;
                if (i > 0 && nums[i - 1] > nums[i + 1]) {
                    nums[i + 1] = nums[i];
                }
            }
        }
        return count < 2;
    }
};