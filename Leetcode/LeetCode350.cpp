// 两个数组的交集II
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// 使用unordered_map记录第一个数组数字出现次数 遍历第二个数组 4ms
class Solution {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mark;
        vector<int> ans;
        for (auto i : nums1) mark[i]++;
        for (auto i : nums2) {
            if (mark.count(i) && mark[i] > 0) {
                mark[i]--;
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// 排序 + 双指针解法
class Solution2 {
   public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int len_a = nums1.size(), len_b = nums2.size();
        vector<int> result;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int pa = 0, pb = 0;
        while (pa < len_a && pb < len_b) {
            if (nums1[pa] < nums2[pb]) {
                ++pa;
            } else if (nums1[pa] > nums2[pb]) {
                ++pb;
            } else {
                result.push_back(nums1[pa]);
                ++pa, ++pb;
            }
        }
        return result;
    }
};