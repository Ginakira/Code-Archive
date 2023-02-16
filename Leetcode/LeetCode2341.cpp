// LeetCode 2341 数组能形成多少数对

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int pairs_count = 0, remain_count = 0;
        for (int num : nums) {
            ++mp[num];
        }
        for (auto& [_, cnt] : mp) {
            pairs_count += cnt >> 1;
            remain_count += cnt & 1;
        }
        return {pairs_count, remain_count};
    }
};