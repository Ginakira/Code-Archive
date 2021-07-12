// LeetCode 1818 绝对差值和

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    static constexpr int MOD = 1e9 + 7;
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        // 对于nums1中的每一位i，假如我们要将该位替换成nums1[j]
        // 则替换前对答案的贡献为|nums1[i] - nums2[i]|，替换后为|nums1[j] - nums2[i]|
        // 差值为diff = |nums1[i] - nums2[i]| - |nums1[j] - nums2[i]|
        // 目标是最小化绝对差值和，所以我们应该让diff尽可能大，则后半部分应该尽可能小
        // 所以nums1[j]应该替换为最接近nums2[i]的数字，可能大于也可能小于
        int n = nums1.size();
        vector<int> vec(nums1);
        sort(vec.begin(), vec.end()); // 方便二分 查找nums1中最接近nums2[i]的数字
        int sum = 0, max_num = 0; // sum为不更改的情况下正常的绝对差值和，max_num为上文中提到的最终的最大的diff
        for (int i = 0; i < n; ++i) {
            int diff = abs(nums1[i] - nums2[i]);
            sum = (sum + diff) % MOD;
            int j = lower_bound(vec.begin(), vec.end(), nums2[i]) - vec.begin(); // 查找第一个大于或等于nums2[i]的数字的下标
            if (j < n) { // 先判断这个大于等于nums2[i]的数，将其和最大diff比对
                max_num = max(max_num, diff - (vec[j] - nums2[i]));
            }
            if (j > 0) { // 同上，第一个大于等于nums2[i]的数的前一位就是比nums2[i]小的最接近它的数，同样统计最大diff
                max_num = max(max_num, diff - (nums2[i] - vec[j - 1]));
            }
        }
        // 计算过程中取模，所以最终可能max_num可能会大于sum，所以先加个MOD再进行取模
        return (sum - max_num + MOD) % MOD;
    }
};