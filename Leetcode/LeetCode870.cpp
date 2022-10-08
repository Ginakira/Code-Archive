// LeetCode 870 优势洗牌

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> ind1(n), ind2(n);
        iota(ind1.begin(), ind1.end(), 0);
        iota(ind2.begin(), ind2.end(), 0);
        sort(ind1.begin(), ind1.end(),
             [&](int i, int j) { return nums1[i] < nums1[j]; });
        sort(ind2.begin(), ind2.end(),
             [&](int i, int j) { return nums2[i] < nums2[j]; });
        int left = 0, right = n - 1;
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (nums1[ind1[i]] > nums2[ind2[left]]) {
                ans[ind2[left]] = nums1[ind1[i]];
                ++left;
            } else {
                ans[ind2[right]] = nums1[ind1[i]];
                --right;
            }
        }
        return ans;
    }
};