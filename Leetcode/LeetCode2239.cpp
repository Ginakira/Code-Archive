// LeetCode 2239 找到最接近0的数字
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
    int findClosestNumber(vector<int>& nums) {
        return *ranges::min_element(nums, [](int a, int b) {
            auto result = abs(a) <=> abs(b);
            if (result < 0) {
                return true;
            } else if (result > 0) {
                return false;
            } else {
                return a > b;
            }
        });
    }
};
