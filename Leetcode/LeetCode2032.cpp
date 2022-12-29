// LeetCode 2032 至少在两个数组中出现的值

#include <algorithm>
#include <array>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int max_num = 0;

    void mark_to_bit(const vector<int>& nums, array<uint8_t, 101>& cnt,
                     uint8_t bitmask) {
        for (auto& num : nums) {
            cnt[num] |= bitmask;
            max_num = max(max_num, num);
        }
    }

   public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2,
                              vector<int>& nums3) {
        array<uint8_t, 101> cnt{0};
        vector<int> ans;
        mark_to_bit(nums1, cnt, 1);
        mark_to_bit(nums2, cnt, 2);
        mark_to_bit(nums3, cnt, 4);
        for (int i = 1; i <= max_num; ++i) {
            if (cnt[i] & (cnt[i] - 1)) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};