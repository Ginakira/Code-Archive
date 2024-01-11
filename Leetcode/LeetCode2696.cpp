// LeetCode 2696 删除子串后的字符串最小长度

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
    int minLength(string s) {
        vector<int> stk;
        stk.reserve(s.size());
        for (char c : s) {
            stk.push_back(c);
            int n = stk.size();
            if (n >= 2 && ((stk[n - 2] == 'A' && stk[n - 1] == 'B') ||
                           (stk[n - 2] == 'C' && stk[n - 1] == 'D'))) {
                stk.pop_back();
                stk.pop_back();
            }
        }
        return stk.size();
    }
};