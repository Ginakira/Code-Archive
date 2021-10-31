// LeetCode 260 只出现一次的数字III
#include <algorithm>
#include <climits>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Solution1: 哈希表
class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }
        vector<int> ans;
        for (const auto& [num, occ] : freq) {
            if (occ == 1) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};

// Solution2: 异或 再分组异或
class Solution2 {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_num = 0;
        for (int num : nums) {
            xor_num ^= num;
        }

        int last_1_bit = xor_num == INT_MIN ? xor_num : xor_num & (-xor_num);
        int type_1 = 0, type_0 = 0;
        for (int num : nums) {
            if (num & last_1_bit) {
                type_1 ^= num;
            } else {
                type_0 ^= num;
            }
        }
        return {type_1, type_0};
    }
};