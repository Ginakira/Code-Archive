// LeetCode 3038 相同分数的最大操作数目

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
    int maxOperations(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int target = nums[0] + nums[1];
        int cnt = 1;
        for (int i = 2; i < nums.size() - 1; i += 2) {
            if (nums[i] + nums[i + 1] != target) {
                break;
            }
            ++cnt;
        }
        return cnt;
    }
};