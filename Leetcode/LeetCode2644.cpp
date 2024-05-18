// LeetCode 2644 找出可整除性得分最大的整数

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
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int res = numeric_limits<int>::max();
        int max_cnt = 0;
        for (auto& div : divisors) {
            int cnt = ranges::count_if(
                nums, [&div](auto& num) { return num % div == 0; });
            if (cnt > max_cnt) {
                max_cnt = cnt;
                res = div;
            } else if (cnt == max_cnt) {
                res = min(res, div);
            }
        }
        return res;
    }
};