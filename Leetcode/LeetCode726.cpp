// LeetCode 726 原子的数量
#include <algorithm>
#include <numeric>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string countOfAtoms(string formula) {
        int index = 0, n = formula.size();

        auto parse_atom = [&]() -> string {  // 解析一个原子
            if (index >= n) {
                return "";
            }
            string atom;
            atom += formula[index++];
            while (index < n && islower(formula[index])) {
                atom += formula[index++];
            }
            return atom;
        };

        auto parse_num = [&]() {  // 解析一个数字
            if (index >= n || !isdigit(formula[index])) return 1;
            int num = 0;
            while (index < n && isdigit(formula[index])) {
                num = num * 10 + formula[index++] - '0';
            }
            return num;
        };

        stack<unordered_map<string, int>> stk;
        stk.push({});

        while (index < n) {
            char ch = formula[index];
            if (ch == '(') {  // 左括号，代表开始新的一层，入栈空的哈希表
                ++index;
                stk.push({});
            } else if (
                ch ==
                ')') {  // 右括号，代表一层结束，取出哈希表，将计数加到外层的哈希表中
                ++index;
                int coefficient = parse_num();  // 括号这一层的系数
                auto prev = stk.top();  // 括号内这一层的哈希表
                stk.pop();
                auto &current = stk.top();  // 外层的哈希表
                for (auto &[atom, num] : prev) {
                    current[atom] += num * coefficient;
                }
            } else {
                string atom = parse_atom();
                int num = parse_num();
                stk.top()[atom] += num;
            }
        }

        auto &root_layer = stk.top();
        vector<tuple<string, int>> atoms;
        for (auto &[atom, num] : root_layer) {
            atoms.emplace_back(atom, num);
        }
        sort(atoms.begin(), atoms.end(),
             [](auto &a, auto &b) { return get<0>(a) < get<0>(b); });

        string result;
        for (auto &[atom, num] : atoms) {
            result += atom + (num > 1 ? to_string(num) : "");
        }
        return result;
    }
};