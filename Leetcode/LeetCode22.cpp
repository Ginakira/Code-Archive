// 每日一题 括号生成
#include <string>
#include <vector>
using namespace std;

// 暴力法 递归生成所有括号序列并判断有效
class Solution {
   private:
    vector<string> result;

    bool check(const string &s) {
        int cnt = 0;
        for (char c : s) {
            if (c == '(') {
                ++cnt;
            } else if (c == ')') {
                --cnt;
            }
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }

    void backtrace(string &s, int n) {
        if (s.size() == n * 2) {
            if (check(s)) {
                result.emplace_back(s);
            }
            return;
        }
        s.push_back('(');
        backtrace(s, n);
        s.pop_back();

        s.push_back(')');
        backtrace(s, n);
        s.pop_back();
        return;
    }

   public:
    vector<string> generateParenthesis(int n) {
        string s;
        backtrace(s, n);
        return result;
    }
};

// 剪枝 + DFS
class Solution2 {
   public:
    void dfs(string current, int l, int r, int n, vector<string> &results) {
        if (r > l || l > n || r > n) return;
        if (l == n && r == n) results.push_back(current);
        dfs(current + '(', l + 1, r, n, results);
        dfs(current + ')', l, r + 1, n, results);
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> results;
        dfs("", 0, 0, n, results);
        return results;
    }
};