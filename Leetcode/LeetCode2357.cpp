// LeetCode 2357 使数组中所有元素都等于零

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        return us.size() - us.count(0);
    }
};