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