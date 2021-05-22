// LeetCode 810 黑板异或游戏
#include <numeric>
#include <vector>
using namespace std;
class Solution {
   public:
    bool xorGame(vector<int>& nums) {
        return !(nums.size() & 1) ||
               !accumulate(nums.begin(), nums.end(), 0, bit_xor());
    }
};