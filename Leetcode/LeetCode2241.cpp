// LeetCode 2241 与对应负数同时存在的最大正整数

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
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int> us;
        for (int num : nums) {
            if (us.count(-num)) {
                ans = max(ans, abs(num));
            }
            us.insert(num);
        }
        return ans;
    }
};

class Solution2 {
   public:
    int findMaxK(vector<int>& nums) {
        int ans = -1;
        unordered_set<int> us;
        for (int num : nums) {
            if (us.count(-num)) {
                ans = max(ans, abs(num));
            }
            us.insert(num);
        }
        return ans;
    }
};