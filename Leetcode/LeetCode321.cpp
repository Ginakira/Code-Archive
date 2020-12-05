// LeetCode 321 拼接最大数
#include <vector>
using namespace std;

// 从nums1选择p个数字，从nums2选择q个数字，分别生成出最大的子序列（单调栈）
// 枚举所有可能的p，q
// 每枚举一次后，将两个最大的子序列合并为一个子序列，维护最大值即可
// 注意合并时，应选取剩余子序列更大的一方push进结果中
// 大小比较：先逐位比较数字，如果都相同，则长度更长的更大【注意一定不能先比较长度】
class Solution {
   public:
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> ans;
        int n = nums1.size(), m = nums2.size();
        int start = max(0, k - m), end = min(k, n);
        for (int i = start; i <= end; ++i) {
            vector<int> nums1_max(maxSubSequence(nums1, i));
            vector<int> nums2_max(maxSubSequence(nums2, k - i));
            vector<int> result(mergeVector(nums1_max, nums2_max));
            if (compareVector(result, 0, ans, 0)) {
                ans.swap(result);
            }
        }
        return ans;
    }

    vector<int> maxSubSequence(vector<int> &nums, int k) {
        int length = nums.size();
        vector<int> stack(k, 0);
        int top = -1;
        int remain = length - k;
        for (int i = 0; i < length; i++) {
            int num = nums[i];
            while (top >= 0 && stack[top] < num && remain > 0) {
                top--;
                remain--;
            }
            if (top < k - 1) {
                stack[++top] = num;
            } else {
                remain--;
            }
        }
        return stack;
    }

    vector<int> mergeVector(vector<int> &vec_a, vector<int> &vec_b) {
        int len_a = vec_a.size(), len_b = vec_b.size();
        if (len_a == 0) return vec_b;
        if (len_b == 0) return vec_a;
        int n = len_a + len_b;
        vector<int> result(n);
        int pa = 0, pb = 0;
        for (int i = 0; i < n; ++i) {
            if (compareVector(vec_a, pa, vec_b, pb)) {
                result[i] = vec_a[pa++];
            } else {
                result[i] = vec_b[pb++];
            }
        }
        return result;
    }

    bool compareVector(vector<int> &a, int index_a, vector<int> &b,
                       int index_b) {
        int na = a.size(), nb = b.size();
        while (index_a < na && index_b < nb) {
            if (a[index_a] != b[index_b]) return a[index_a++] > b[index_b++];
            ++index_a, ++index_b;
        }
        return (na - index_a) > (nb - index_b);
    }
};