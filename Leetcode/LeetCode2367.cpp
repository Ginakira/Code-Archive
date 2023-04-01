// LeetCode 2367 算数三元组的数目

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> us;
        int ans = 0;
        for (int num : nums) {
            us.emplace(num);
            if (us.count(num - diff) && us.count(num - diff * 2)) {
                ++ans;
            }
        }
        return ans;
    }
};