// LeetCode 2956 找到两个数组中的公共元素

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
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2) {
        auto helper = [](const vector<int> &ref, const vector<int> &cmp) {
            int cnt = 0;
            unordered_set<int> us(ref.begin(), ref.end());
            for (auto &num : cmp) {
                if (us.count(num)) {
                    ++cnt;
                }
            }
            return cnt;
        };
        return {helper(nums2, nums1), helper(nums1, nums2)};
    }
};