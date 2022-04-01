// LeetCode 954 二倍数对数组

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            ++freq[num];
        }
        if (freq[0] & 1) {
            return false;
        }
        vector<int> nums;
        nums.reserve(freq.size());
        for (auto& [key, _] : freq) {
            nums.push_back(key);
        }
        sort(nums.begin(), nums.end(),
             [](int a, int b) { return abs(a) < abs(b); });

        for (int num : nums) {
            if (freq[num * 2] < freq[num]) {
                return false;
            }
            freq[num * 2] -= freq[num];
        }
        return true;
    }
};