// LeetCode 131 分割回文串
#include <string>
#include <vector>
using namespace std;

// 回溯法 112ms
// 每次分割出一个回文字符串 然后继续分割剩下的部分
class Solution {
   public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ret;
        vector<string> current;
        dfs(s, 0, n, current, ret);
        return ret;
    }

    void dfs(string &s, int start, int n, vector<string> &current,
             vector<vector<string>> &ret) {
        if (start == n) {
            ret.emplace_back(current);
            return;
        }
        for (int i = start; i < n; ++i) {
            if (!is_palindrome(s, start, i)) continue;
            current.emplace_back(s.substr(start, i - start + 1));
            dfs(s, i + 1, n, current, ret);
            current.pop_back();
        }
    }

    bool is_palindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};

// dp预处理 优化回文串判定

class Solution2 {
   private:
    vector<vector<string>> ret;
    vector<string> current;
    vector<vector<int>> dp;
    int n;

   public:
    void dfs(const string &s, int start) {
        if (start == n) {
            ret.emplace_back(current);
            return;
        }
        for (int i = start; i < n; ++i) {
            if (!dp[start][i]) continue;
            current.emplace_back(s.substr(start, i - start + 1));
            dfs(s, i + 1);
            current.pop_back();
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        n = s.size();
        // dp预处理 dp[i][j]代表字符串s以i开头j结尾的子串是回文串
        dp.assign(n, vector<int>(n, 1));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
        dfs(s, 0);
        return ret;
    }
};