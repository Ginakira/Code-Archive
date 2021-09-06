// 剑指 Offer 56 - I. 数组中数字出现的次数
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0, y = 0, n = 0, m = 1;
        for (int num : nums) {
            n ^= num;
        }
        while (!(n & m)) {
            m <<= 1;
        }
        for (int num : nums) {
            if (num & m) {
                x ^= num;
            } else {
                y ^= num;
            }
        }
        return vector<int>{x, y};
    }
};