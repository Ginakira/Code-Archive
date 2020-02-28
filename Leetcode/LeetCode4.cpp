// 寻找两个有序数组的中位数
#include <vector>
using namespace std;

// 暴力合并法 40ms 91.8MB O(m + n)
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lena = nums1.size(), lenb = nums2.size(), n = lena + lenb;
        vector<double> ans;
        for (int p = 0, q = 0, k = 0; k <= n / 2; ++k) {
            if (q >= lenb || (p < lena && nums1[p] < nums2[q])) {
                ans.push_back(nums1[p++]);
            } else {
                ans.push_back(nums2[q++]);
            }
        }
        return (n & 1) ? ans[n >> 1] : (ans[n / 2 - 1] + ans[n / 2]) / 2.0;
    }
};