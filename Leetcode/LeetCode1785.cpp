// LeetCode 1785 构成特定和需要添加到最少元素

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = accumulate(nums.begin(), nums.end(), 0L);
        long long diff = abs(goal - sum);
        return (diff + limit - 1) / limit;
    }
};