// LeetCode 3131 找出与数组相加的整数 I

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
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        return *ranges::min_element(nums2) - *ranges::min_element(nums1);
    }
};