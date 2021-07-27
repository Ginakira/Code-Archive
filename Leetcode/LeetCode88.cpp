// 合并两个有序数组
#include <vector>
using namespace std;

// 4ms 使用新数组
class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (j >= n || (i < m && nums1[i] < nums2[j]))
                ans.push_back(nums1[i++]);
            else
                ans.push_back(nums2[j++]);
        }
        nums1 = ans;
        return;
    }
};

// 0ms 因为nums1有足够空间 所以从nums1末尾从后向前存较大的数
class Solution2 {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = n + m - 1, i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        while (j >= 0) nums1[k--] = nums2[j--];
        return;
    }
};

class Solution3 {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pa = m - 1, pb = n - 1, p = nums1.size() - 1;
        while (pa >= 0 || pb >= 0) {
            if (pb < 0 || (pa >= 0 && nums1[pa] > nums2[pb])) {
                nums1[p--] = nums1[pa--];
            } else {
                nums1[p--] = nums2[pb--];
            }
        }
        return;
    }
};