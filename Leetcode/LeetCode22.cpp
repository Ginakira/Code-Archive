// 每日一题 括号生成
#include <string>
#include <vector>
using namespace std;

// 暴力法 递归生成所有括号序列并判断有效
class Solution {
   public:
    bool is_valid(const string &str) {
        int match = 0;
        for (char c : str) {
            if (c == '(') {
                match++;
            } else {
                match--;
                if (match < 0) return false;
            }
        }
        return match == 0;
    }

    void generate_brackets(string &current, int n, vector<string> &results) {
        if (current.size() == n) {
            if (is_valid(current)) results.push_back(current);
            return;
        }
        current += '(';
        generate_brackets(current, n, results);
        current.pop_back();
        current += ')';
        generate_brackets(current, n, results);
        current.pop_back();
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> results;
        string current = "";
        generate_brackets(current, n << 1, results);
        return results;
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