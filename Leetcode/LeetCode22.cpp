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