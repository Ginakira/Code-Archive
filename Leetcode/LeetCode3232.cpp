// LeetCode 3232 判断是否可以赢得数字游戏

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
    bool canAliceWin(vector<int>& nums) {
        int sum = 0;
        int one_sum = 0, two_sum = 0;
        for (int num : nums) {
            if (num < 10) {
                one_sum += num;
            } else if (num < 100) {
                two_sum += num;
            }
            sum += num;
        }
        int target = sum / 2;
        return one_sum > target || two_sum > target;
    }
};
a