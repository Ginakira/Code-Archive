// LeetCode 3258 统计满足K约束的子字符串数量I

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
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int zero_cnt = 0, one_cnt = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] == '0') {
                    ++zero_cnt;
                } else {
                    ++one_cnt;
                }
                if (zero_cnt > k && one_cnt > k) {
                    break;
                }
                ++ans;
            }
        }
        return ans;
    }
};