// LeetCode 842 将数组拆分成斐波那契数列
#include <climits>
#include <string>
#include <vector>
using namespace std;

// Solution：DFS + 回溯
class Solution {
   public:
    vector<int> ans;

    vector<int> splitIntoFibonacci(string S) {
        if (dfs(S, 0)) return ans;
        return {};
    }

    bool check() {  // 检查当前的状态是否合法
        if (ans.size() < 3) return true;
        return (long long)ans.back() ==
               (long long)ans[ans.size() - 2] + (long long)ans[ans.size() - 3];
    }

    bool dfs(string &s, int ind) {
        if (ind >= s.size()) {  // 递归出口
            return ans.size() > 2;
        }
        if (s[ind] == '0') {  // 如果开头这一位是0，那么只能其自己组成一个数
            ans.push_back(0);
            if (check() && dfs(s, ind + 1))
                return true;  // 如果当前状态合法且后续能找到答案
            ans.pop_back();   // 回溯
            return false;
        }

        long long cur = 0;
        while (ind < s.size()) {
            cur = cur * 10 + (s[ind++] - '0');
            if (cur > INT_MAX) return false;
            ans.push_back(cur);
            if (check() && dfs(s, ind)) return true;
            ans.pop_back();
        }
        return false;
    }
};