// LeetCode 1295 统计位数为偶数的数字

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
    int findNumbers(vector<int>& nums) {
        return ranges::count_if(nums, [](int num) {
            if (num == 0) return false;
            return !(int(floor(log10(num)) + 1) & 1);
        });
    }
};