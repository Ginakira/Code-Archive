// LeetCode 3132 找出与数组相加的整数II

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        ranges::sort(nums1);
        ranges::sort(nums2);
        for (int i : {2, 1, 0}) {
            int left = i + 1, right = 1;
            while (left < n && right < m) {
                if (nums1[left] - nums2[right] == nums1[i] - nums2[0]) {
                    ++right;
                }
                ++left;
            }
            if (right == m) {
                return nums2[0] - nums1[i];
            }
        }
        return 0;
    }
};
