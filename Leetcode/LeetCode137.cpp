// LeetCode137 只出现一次的数字II

#include <unordered_map>
#include <vector>
using namespace std;

// map 8ms 9.8MB
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int& num : nums) {
            ++mp[num];
            if (mp[num] == 3) {
                mp.erase(num);
            }
        }
        return mp.begin()->first;
    }
};

// 分别确定每一个二进制位 8ms 9.2MB
class Solution2 {
   public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int total = 0;
            for (int& num : nums) {
                total += (num >> i) & 1;
            }
            if (total % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};