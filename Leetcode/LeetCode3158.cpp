// LeetCode 3158 求出出现两次数字的XOR值

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
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> us;
        int ans = 0;
        for (int num : nums) {
            if (us.count(num)) {
                ans ^= num;
            } else {
                us.emplace(num);
            }
        }
        return ans;
    }
};