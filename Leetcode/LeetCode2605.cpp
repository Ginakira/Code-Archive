// LeetCode 2605 从两个数字数组力生成最小数字

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
    int minNumber(vector<int> &nums1, vector<int> &nums2) {
        auto min_same = [&]() {
            int ret = 10;
            unordered_set<int> seen(nums1.begin(), nums1.end());
            for (auto num : nums2) {
                if (seen.count(num)) {
                    ret = min(ret, num);
                }
            }
            return ret;
        };
        if (int x = min_same(); x != 10) {
            return x;
        }
        int a = *min_element(nums1.begin(), nums1.end());
        int b = *min_element(nums2.begin(), nums2.end());
        return min(a * 10 + b, b * 10 + a);
    }
};
