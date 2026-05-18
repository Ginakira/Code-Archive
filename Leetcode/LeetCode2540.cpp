// LeetCode 2540 最小公共值

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
  int getCommon(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.back() < nums2[0] || nums1[0] > nums2.back()) {
      return -1;
    }
    for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
      if (nums1[i] == nums2[j]) {
        return nums1[i];
      } else if (nums1[i] < nums2[j]) {
        ++i;
      } else {
        ++j;
      }
    }
    return -1;
  }
};