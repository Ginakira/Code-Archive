// LeetCode 1413 逐步求和得到正数的最小值

#include <algorithm>
#include <limits>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minStartValue(vector<int>& nums) {
        int min_presum = std::numeric_limits<int>::max(), sum = 0;
        for (int num : nums) {
            sum += num;
            min_presum = min(min_presum, sum);
        }
        return (min_presum > 0 ? 1 : -min_presum + 1);
    }
};