// LeetCode 2455 可被三整除的偶数的平均值

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
    int averageValue(vector<int>& nums) {
        int sum = 0, count = 0;
        for (int num : nums) {
            if (!(num & 1) && num % 3 == 0) {
                ++count;
                sum += num;
            }
        }
        return count ? sum / count : 0;
    }
};