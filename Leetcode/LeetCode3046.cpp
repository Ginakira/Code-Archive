// LeetCode 3046 分割数组

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
    bool isPossibleToSplit(vector<int>& nums) {
        std::array<int, 101> cnt;
        for (int num : nums) {
            if (++cnt[num] > 2) {
                return false;
            }
        }
        return true;
    }
};