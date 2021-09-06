// 剑指 Offer 56 - II. 数组中数字出现的次数 II

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};
        for (int num : nums) {
            for (int i = 0; i < 32; ++i) {
                count[i] += num & 1;
                num >>= 1;
            }
        }
        int result = 0;
        for (int i = 31; i >= 0; --i) {
            result <<= 1;
            result |= count[i] % 3;
        }
        return result;
    }
};