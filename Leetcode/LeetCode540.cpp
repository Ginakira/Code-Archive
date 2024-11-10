// LeetCode 540 有序数组中的单一元素

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
    int singleNonDuplicate(vector<int>& nums) {
        return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor());
    }
};