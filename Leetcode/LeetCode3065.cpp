// LeetCode 3065 超过阈值的最少操作数 I

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
    int minOperations(vector<int>& nums, int k) {
        return ranges::count_if(nums, [k](int num) { return num < k; });
    }
};