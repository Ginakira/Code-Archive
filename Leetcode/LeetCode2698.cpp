// LeetCode 2698 求一个整数的惩罚数

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
   private:
    bool dfs(const string &s, int pos, int sum, int target) {
        if (pos == s.size()) {
            return sum == target;
        }
        int cur_sum = 0;
        for (int i = pos; i < s.size(); ++i) {
            cur_sum = cur_sum * 10 + s[i] - '0';
            if (sum + cur_sum > target) {
                break;
            }
            if (dfs(s, i + 1, sum + cur_sum, target)) {
                return true;
            }
        }
        return false;
    }

   public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int num = i * i;
            auto s = to_string(num);
            if (dfs(s, 0, 0, i)) {
                ans += num;
            }
        }
        return ans;
    }
};
