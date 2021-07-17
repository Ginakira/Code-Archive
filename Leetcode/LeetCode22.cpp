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
   private:
    vector<string> result;

    void dfs(string s, int left_used, int right_used, int n) {
        if (right_used > left_used || left_used > n || right_used > n) {
            return;
        }
        if (left_used == n && right_used == n) {
            result.emplace_back(s);
        }
        dfs(s + "(", left_used + 1, right_used, n);
        dfs(s + ")", left_used, right_used + 1, n);
        return;
    }

   public:
    vector<string> generateParenthesis(int n) {
        dfs("", 0, 0, n);
        return result;
    }
};